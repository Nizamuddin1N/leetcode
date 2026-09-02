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
    // vector<int>list;
    // void solve(TreeNode* root){
    //     if(root==nullptr){
    //         return;
    //     }
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode* node = q.front();
    //         q.pop();
    //         list.push_back(node->val);
    //         if(node->left){
    //             q.push(node->left);
    //         }
    //         if(node->right){
    //             q.push(node->right);
    //         }
    //     }
    //     return;
    // }
    // TreeNode* maxBinarytree(vector<int>&list,  int left, int right){
    //     if(left>right){
    //         return nullptr;
    //     }
    //     int maxIndex = left;
    //     for(int i=left; i<=right; i++){
    //         if(list[maxIndex]<list[i]){
    //             maxIndex = i;
    //         }
    //     }
    //     TreeNode* node = new TreeNode(list[maxIndex]);
    //     node->left = maxBinarytree(list, left, maxIndex-1);
    //     node->right = maxBinarytree(list, maxIndex+1, right);
    //     return node;
    // }
    // void solve(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }
    //     solve(root->left);
    //     solve(root->right);
    //     if(root->left && root->left->val > root->val){
    //         swap(root->left->val, root->val);
    //     }
    //     if(root->right && root->right->val > root->val){
    //         swap(root->right->val, root->val);
    //     }
    // }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // // solve(root);
        // // list.push_back(val);
        // // return maxBinarytree(list, 0, list.size()-1);
        // queue<TreeNode*> q;
        // q.push(root);
        // TreeNode* temp;
        // while(!q.empty()){
        //     TreeNode* node = q.front();
        //     temp = node;
        //     q.pop();
        //     if(node->left){
        //         q.push(node->left);
        //     }
        //     if(node->right){
        //         q.push(node->right);
        //     }
        // }
        // temp->left = new TreeNode(val);
        // solve(root);
        // return root;
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(val>root->val){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};