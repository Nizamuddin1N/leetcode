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
    string solve(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){
            return to_string(root->val);
        }
        string s = to_string(root->val);
        if(root->left){
          string left = solve(root->left);
          s+="(" +left + ")";

        }
        if(root->left == nullptr){
            s += "()";
        }
        if(root->right){
           string right =  solve(root->right);
           s += "(" + right + ")";
        }
        return s;
    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};