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
    pair<int, int> solve(TreeNode* root, int& ans){
        if(root == nullptr){
            return {0, 0};
        }
        pair<int, int> left = solve(root->left, ans);
        pair<int, int> right = solve(root->right, ans);
        int leftzigzag=0;
        int rightzigzag=0;
        if(root->left != nullptr){
            leftzigzag = 1 + left.second;
        }
        if(root->right != nullptr){
            rightzigzag = 1 + right.first;
        }
        ans = max(ans, max(leftzigzag, rightzigzag));
        return {leftzigzag, rightzigzag};
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        solve(root, ans);
        return ans;
    }
};