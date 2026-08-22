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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        int ans=0;
        st.push({root, root->val});
        while(!st.empty()){
            auto[node, maxElement] = st.top();
            st.pop();
            if(node == nullptr){
                continue;
            }
            if(node->val>=maxElement){
                ans++;
            }
            int newMax = max(maxElement, node->val);
            if(node->left){
                st.push({node->left, newMax});
            }
            if(node->right){
                st.push({node->right, newMax});
            }
        }
        return ans;
    }
};