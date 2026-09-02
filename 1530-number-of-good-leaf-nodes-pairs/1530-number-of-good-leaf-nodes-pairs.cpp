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
    vector<int> dfs(TreeNode* root, int d){
        if(root->left == nullptr &&  root->right == nullptr){
            vector<int> cnt(d+1, 0);
            cnt[0]=1;
            return cnt;
        }
        vector<int>leftcnt(d+1, 0);
        vector<int>rightcnt(d+1, 0);
        if(root->left){
            leftcnt = dfs(root->left, d);
        }
        if(root->right){
            rightcnt = dfs(root->right, d);
        }
        for(int i=0; i<=d; i++){
            for(int j=0; j<=d; j++){
                if(i+j+2<=d){
                    ans +=leftcnt[i]*rightcnt[j];
                }
            }
        }
        vector<int>current(d+1, 0);
        for(int i=0; i<d; i++){
            current[i+1] += leftcnt[i];
            current[i+1] += rightcnt[i];
        }
        return current;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};