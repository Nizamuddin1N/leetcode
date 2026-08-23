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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans = accumulate(level.begin(), level.end(), 0);
        }
        return ans;
    }
};