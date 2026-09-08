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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        if(root->left == nullptr && root->right == nullptr){
            return {root->val};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n = q.size();
            int max=INT_MIN;
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                if(max <= temp->val){
                    max = q.front()->val;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
            }
            ans.push_back(max);
        }
        return ans;
    }
};