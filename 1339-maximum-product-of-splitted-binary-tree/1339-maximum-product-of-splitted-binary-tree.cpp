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
    int number= INT_MAX;
    int half;
    const int MOD = 1e9+7;
    int sumofbinarytree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = sumofbinarytree(root->left);
        int right = sumofbinarytree(root->right);
        return left + right + root->val;
    }
    int sumofbinarytree2(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = sumofbinarytree2(root->left);
        int right = sumofbinarytree2(root->right);
        int sum = left + right + root->val;
        if(abs(number - half) > abs(sum-half)){
            number = sum;
        }
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int sum = sumofbinarytree(root);
        int half1 = sum/2;
        if(sum%2 != 0){
            half1++;
        }
        half = half1;
        sumofbinarytree2(root);
        int number2 = sum-number;
        return (1LL * number2*number)%MOD;
    }
};