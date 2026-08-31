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
    vector<TreeNode*>ans;
    void function(TreeNode* root, set<int> &s, TreeNode* parent){
        if(root == nullptr){
            return;
        }
        function(root->left, s, root);
        function(root->right, s, root);
        if(s.find(root->val) != s.end()){
            if(root->left){
                ans.push_back(root->left);
                root->left = nullptr;
            }
            if(root->right){
                ans.push_back(root->right);
                root->right = nullptr;
            }
            if(parent != nullptr){
                if(parent->left == root){
                   parent->left=nullptr;
                }
                if(parent->right == root){
                    parent->right=nullptr;
                }
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        if(root == nullptr){
            return {nullptr};
        }
        if (s.find(root->val) == s.end()) {
            ans.push_back(root);
        }
        TreeNode* parent = nullptr;
        function(root, s, parent);
        return ans;
    }
};