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
    int limit;
    int solve(TreeNode* root, int sum){
        if(root == nullptr){
            return INT_MIN;
        }
        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }
        int left = INT_MIN;
        int right = INT_MIN;
        if(root->left){
            left = solve(root->left, sum +root->left->val);
        }
        if(root->right){
            right = solve(root->right, sum + root->right->val);
        }
        if(root->left && left<limit){
            root->left = nullptr;
        }
        if(root->right && right<limit){
            root->right = nullptr;
        }
        return max(right, left);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        this->limit = limit;        
        int sum = solve(root, root->val);
        if(sum<limit){
            return nullptr;
        }
        return root;
    }
};