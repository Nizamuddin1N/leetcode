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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*> q;
        if(root1 != nullptr){
            q.push(root1);
        }
        while(!q.empty() && root1 != nullptr){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        if(root2 != nullptr){
            q.push(root2);
        }
        while(!q.empty() && root2 != nullptr){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};