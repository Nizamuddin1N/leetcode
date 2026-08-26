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
    void storeInorder(TreeNode* root, vector<int> &inorder){
        if(root == nullptr){
            return;
        }
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }
    TreeNode* inorderToBST(int s, int e, vector<int> &inorder){
        if(s>e){
            return NULL;
        }
        TreeNode* root = new TreeNode(inorder[s]);
        root->right = inorderToBST(s+1, e, inorder);
        return root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        storeInorder(root, inorder);
        int n = inorder.size();
        return inorderToBST(0, n-1, inorder);
    }
};