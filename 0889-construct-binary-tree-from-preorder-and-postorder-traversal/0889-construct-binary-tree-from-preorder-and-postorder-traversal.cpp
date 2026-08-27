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
    TreeNode* build(vector<int>& preorder, int minPre, int maxPre, vector<int>& postorder, int minPos, int maxPos){
        if(minPre>maxPre){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[minPre]);
        if(minPre == maxPre){
            return root;
        }

        int leftRoot = preorder[minPre+1];
        int pos=minPos;
        while(leftRoot != postorder[pos]){
            pos++;
        }
        int leftSize = pos+1-minPos;
        root->left = build(preorder, minPre+1, minPre+leftSize, postorder, minPos, pos);
        root->right = build(preorder, minPre+leftSize+1, maxPre, postorder, pos+1, maxPos-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int min = 0, max = preorder.size();
        return build(preorder, min, max-1, postorder, min, max-1);
    }
};