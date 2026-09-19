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
    vector<int>ans;
    int i = 0;
    bool solve(TreeNode* root, vector<int>& voyage){
        if(root == nullptr){
            return true;
        }
        if (root->val != voyage[i]) {
            return false;
        }
        i++;
        if(root->left && root->left->val != voyage[i]){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            ans.push_back(root->val);
        }
        
        if(root->left && root->left->val != voyage[i]){
            return false;
        }
        bool left = solve(root->left, voyage);
        bool right = solve(root->right, voyage);
        return left & right;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root->val != voyage[i]){
            return {-1};
        }
        if(solve(root, voyage)){
            return ans;
        }
        return {-1};
    }
};