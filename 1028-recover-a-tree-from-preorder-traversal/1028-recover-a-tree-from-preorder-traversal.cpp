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
    TreeNode* solve(string &s, int &i, int depth){
        int j=i;
        int d=0;
        int n = s.size();
        while(j<n && s[j]=='-'){
            j++;
            d++;
        }
        if(d != depth){
            return nullptr;
        }
        i=j;
        int num=0;
        while(i<n && isdigit(s[i])){
            num = num*10 + (s[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        root->left = solve(s, i, depth+1);
        root->right = solve(s, i, depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return solve(traversal, i, 0);
    }
};