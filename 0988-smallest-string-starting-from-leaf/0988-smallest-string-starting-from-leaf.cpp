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
    string path = "";
    string ans = "";
    void solve(TreeNode* root){
        if(root == nullptr){
            return;
        }
        path.push_back('a'+ root->val);
        if(root->left == nullptr && root->right == nullptr){
            string temp = path;
            reverse(temp.begin(), temp.end());
            if(ans == "" || temp<ans){
                ans = temp;
            }
        }
        solve(root->left);
        solve(root->right);
        path.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root);
        return ans;
    }
};