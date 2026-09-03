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
    bool checkPath(unordered_map<int, int>mp){
        int freqOdd=0;
        int totalFreq = 0;
        for(auto&[digit, frequency] : mp){
            if(frequency %2 != 0){
                freqOdd++;
            }
            totalFreq +=frequency;
        }
        if(totalFreq % 2 == 0){
            if(freqOdd>0){
                return false;
            }
        }
        else if(totalFreq % 2 != 0){
            if(freqOdd>1){
                return false;
            }
        }
        return true;
    }
    void solve(TreeNode* root, unordered_map<int, int>&mp){
        mp[root->val]++;
        if(root->left == nullptr && root->right == nullptr){
            if(checkPath(mp)){
                ans++;
            }
            mp[root->val]--;
            return;
        }
        if(root->left){
            solve(root->left, mp);
        }
        if(root->right){
            solve(root->right, mp);
        }
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);
        return ans;
    }
};