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
    int countNodes(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1+countNodes(root->left) + countNodes(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xNode = nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == x){
                xNode = node;
                break;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        int leftnodes = countNodes(xNode->left);
        int rightnodes = countNodes(xNode->right);
        int aboveNodes = n-leftnodes - rightnodes-1;
        int largest = max({leftnodes, rightnodes, aboveNodes});
        return largest>n/2;

    }
};