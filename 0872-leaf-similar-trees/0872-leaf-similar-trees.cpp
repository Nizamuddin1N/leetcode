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
    vector<int> leafnodes(TreeNode* root){
        stack<TreeNode*>st;
        st.push(root);
        vector<int>leafnodes;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left == nullptr && node->right == nullptr){
                leafnodes.push_back(node->val);
            }
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        return leafnodes;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr){
            return false;
        }
        vector<int>leafnodes1;
        vector<int>leafnodes2;
        leafnodes1 =  leafnodes(root1);
        leafnodes2 =  leafnodes(root2);
        return leafnodes1 == leafnodes2;
    }
};