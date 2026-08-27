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
    //finding sum for each parent node
    unordered_map<int, int>mp;
    void findLevelSum(TreeNode* root, int level){
        if(root == nullptr){
            return;
        }
        mp[level] += root->val;
        findLevelSum(root->left, level+1);
        findLevelSum(root->right, level+1);
    }

    void replace(TreeNode* root, int level){
        if(root == nullptr){
            return;
        }
        if(level == 0){
            root->val = 0;
        }
        if(root->left || root->right){
            int childSum=0;
            if(root->left){
                childSum += root->left->val;
            }
            if(root->right){
                childSum += root->right->val;
            }
            int newValue = mp[level+1] - childSum;
            if(root->left){
                root->left->val = newValue;
            }
            if(root->right){
                root->right->val = newValue;
            }
        }
        replace(root->left, level+1);
        replace(root->right, level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        findLevelSum(root, 0);
        replace(root, 0);
        return root;
    }
};