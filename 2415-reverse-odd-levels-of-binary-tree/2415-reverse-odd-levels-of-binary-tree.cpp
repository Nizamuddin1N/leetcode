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
    void reverseEachOddLevel(TreeNode* root){
        if(root == nullptr){
            return;
        }
        int check=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            check++;
            int size = q.size();
            vector<TreeNode*>level;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            int i=0; 
            int j=level.size()-1;
            while(i<j && check%2 !=1){
                swap(level[i]->val, level[j]->val);
                i++;
                j--;
            }
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseEachOddLevel(root);
        return root;
    }
};