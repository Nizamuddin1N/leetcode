/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int>height;
    unordered_map<int, int>answer;
    int heightofsubtree(TreeNode* root){
        if(root == nullptr){
            return -1;
        }
        int left = heightofsubtree(root->left);
        int right = heightofsubtree(root->right);
        height[root] = 1+max(left, right);
        return height[root];
    }
    void dfs(TreeNode* root, int depth, int outside){
        if(root == nullptr){
            return;
        }
        answer[root->val] = outside;
        int leftheight = root->left ? height[root->left] : -1;
        int rightheight = root->right ? height[root->right] : -1;

        int leftoutside = max(outside, depth + 1 + rightheight);
        int rightoutside = max(outside, depth + 1 + leftheight);
        dfs(root->left, depth+1, leftoutside);
        dfs(root->right, depth+1, rightoutside);
    }
    // int maxheight(TreeNode* root, int value){
    //     if(root == nullptr){
    //         return 0;
    //     }
    //     if(root->val == value){
    //         return 0;
    //     }
    //     int left = maxheight(root->left, value);
    //     int right = maxheight(root->right, value);
    //     return 1 + max(left, right);
    // }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // vector<int>ans;
        // for(int q : queries){
        //     ans.push_back(maxheight(root, q)-1);
        // }
        // return ans;
        heightofsubtree(root);
        dfs(root, 0, 0);
        vector<int>ans;
        for(int q:queries){
            ans.push_back(answer[q]);
        }
        return ans;
    }
};