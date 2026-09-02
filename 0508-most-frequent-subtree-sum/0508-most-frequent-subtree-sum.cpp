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
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int sum = left + right + root->val;
        if(mp.find(sum) != mp.end()){
            mp[sum]++;
        }
        else{
            mp.insert({sum, 1});
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        if(mp.size() == 1){
            return {mp.begin()->first};
        }
        int maxfrequent = INT_MIN;
        for(auto& [key, value] : mp){
            maxfrequent = max(maxfrequent, value);
        }
        vector<int>ans;
        for(auto& [key, value] : mp){
            if(value==maxfrequent){
                ans.push_back(key);
            }
        }
        return ans;
    }
};