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
    int postorder(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = postorder(root->left);
        int right = postorder(root->right);
        if(left==0){
            if(root->left){
                root->left = nullptr;
            }
        }
        if(right == 0){
            if(root->right){
                root->right = nullptr;
            }
        }
        return left+right+root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        postorder(root);
        if (root != nullptr && root->val == 0 &&
            root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
};