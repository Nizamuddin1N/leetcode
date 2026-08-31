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
    int ans=0;
    int solve(TreeNode* root){
        if(root == nullptr){
            return INT_MIN;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int maximum = max(root->val, max(left, right));
        if(root->val >= maximum){
            ans++;
        }
        return maximum;
    }
    int countDominantNodes(TreeNode* root) {
        int max = INT_MIN;
        solve(root);
        return ans;
    }
};