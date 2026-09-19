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
    set<int>st;
    void valuestore(TreeNode* root){
        if(root==nullptr){
            return;
        }
        st.insert(root->val);
        valuestore(root->left);
        valuestore(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        valuestore(root);
        if(st.size()<2){
            return -1;
        }
        auto it = st.begin();
        it++;
        return *it;
    }
};