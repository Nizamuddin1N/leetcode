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
    int m, n;
    int height;
    int heightofbinarytree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1+max(heightofbinarytree(root->left), heightofbinarytree(root->right));
    }
    void buildingMatrix(TreeNode* root, int r, int c, vector<vector<string>> &res){
        if(r >= m || r < 0 || c >= n || c < 0 || root == nullptr){
            return;
        }
        res[r][c] = to_string(root->val);
        int value = pow(2, height-r-2);
        buildingMatrix(root->left, r+1, c-value, res);
        buildingMatrix(root->right, r+1, c+value, res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        //count height of tree
        height = heightofbinarytree(root);
        m = height;
        n = pow(2, height)-1;
        vector<vector<string>>res(m, vector<string>(n, ""));
        int r=0;
        int c=(n-1)/2;
        buildingMatrix(root, r, c, res);
        return res;
    }
};