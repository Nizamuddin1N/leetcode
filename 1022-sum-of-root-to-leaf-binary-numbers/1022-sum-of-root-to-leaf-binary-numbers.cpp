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
    int ans = 0;
    void solve(TreeNode* root, string &s){
        if(root == nullptr){
            return;
        }
        s = s + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            ans +=  stoi(s, nullptr, 2);
        }
        solve(root->left, s);
        solve(root->right, s);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        solve(root, s);
        return ans;
    }
};