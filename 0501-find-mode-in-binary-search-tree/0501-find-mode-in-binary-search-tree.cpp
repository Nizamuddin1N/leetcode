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
    unordered_map<int, int>mp;
    void storeFrequency(TreeNode* root){
        if(root == nullptr){
            return;
        }
        mp[root->val]++;
        storeFrequency(root->left);
        storeFrequency(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int maxFrequency=INT_MIN;
        storeFrequency(root);
        for(auto &e:mp){
            maxFrequency = max(maxFrequency, e.second);
        }
        vector<int>ans;
        for(auto &e:mp){
            if(e.second == maxFrequency){
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};