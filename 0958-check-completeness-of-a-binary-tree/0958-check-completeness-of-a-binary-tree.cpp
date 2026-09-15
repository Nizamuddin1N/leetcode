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
    // int heightofbinaryTree(TreeNode* root){
    //     if(root == nullptr){
    //         return 0;
    //     }
    //     int left = heightofbinaryTree(root->left);
    //     int right = heightofbinaryTree(root->right);
    //     return 1 + max(left, right);
    // }
    bool isCompleteTree(TreeNode* root) {
        // int height = heightofbinaryTree(root);
        // int h =1;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     vector<TreeNode*>lastlevel;
        //     for(int i=0; i<n; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         lastlevel.push_back(node);
        //         if (node != nullptr) {
        //             q.push(node->left);
        //             q.push(node->right);
        //         }

        //     }
        //     if(h==height){
        //         for(int i=1; i<lastlevel.size(); i++){
        //             if(lastlevel[i-1] != nullptr && lastlevel[i]==nullptr){
        //                 return false;
        //             }
        //         }
        //         return false;
        //     }
        //     h++;
        // }
        // return true;
        queue<TreeNode*>q;
        q.push(root);
        bool isNull = false;
        while(!q.empty()){
            TreeNode* node  = q.front();
            q.pop();
            if(node == nullptr){
                isNull=true;
                continue;
            }
            if(isNull){
                return false;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};