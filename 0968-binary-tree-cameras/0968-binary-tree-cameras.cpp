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
    int ans=0;
    // int solve(TreeNode* root){
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     int level = 1;
    //     int prevlevelnodes=0;
    //     int currnnumnodes = 0;
    //     while(!q.empty()){
    //         int n=q.size();
    //         currnnumnodes = n;
    //         if(level % 3 == 0){
    //             ans += prevlevelnodes;
    //         }
    //         for(int i=0; i<n; i++){
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if(node->left){
    //                 q.push(node->left);
    //             }
    //             if(node->right){
    //                 q.push(node->right);
    //             }
    //         }
    //         if(!q.empty()){
    //             prevlevelnodes=currnnumnodes;
    //         }
    //         level++;
    //     }
    //     level--;
    //     if(level % 3 == 1 && (currnnumnodes < prevlevelnodes)){
    //         ans += currnnumnodes;
    //     }
    //     else if(level %3 != 0){
    //         ans += prevlevelnodes;
    //     }
    //     return ans;
    // }
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 2;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == 0 || right == 0){
            ans++;
            return 1;
        }
        if(left == 1 || right == 1){
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        // if(root->left == nullptr && root->right == nullptr){
        //     return 1;
        // }
        // solve(root);
        if(dfs(root) == 0){
            ans++;
        }
        return ans;
    }
};