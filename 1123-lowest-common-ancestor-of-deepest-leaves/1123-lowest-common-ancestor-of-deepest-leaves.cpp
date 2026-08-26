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
    TreeNode* solve(TreeNode* root, unordered_set<TreeNode*> &st){
        if(root == nullptr){
            return nullptr;
        }
        if(st.find(root) != st.end()){
            return root;
        }
        TreeNode* leftAns = solve(root->left, st);
        TreeNode* rightAns = solve(root->right, st);
        if(leftAns != nullptr && rightAns != nullptr){
            return root;
        }
        else if(leftAns != nullptr && rightAns == nullptr){
            return leftAns;
        }
        else if(leftAns == nullptr && rightAns != nullptr){
            return rightAns;
        }
        else{
            return nullptr;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_set<TreeNode*>st;
        queue<TreeNode*>q;
        if(root==NULL){
            return NULL;
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            st.clear();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                st.insert(node);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return solve(root, st);
    }
};