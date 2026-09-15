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
    int currcount=0;
    int maxcount=0;
    int prev=0;
    bool hasprev = false;
    vector<int>ans;
    void solve(TreeNode* root){
        if(root==nullptr){
            return;
        }
        solve(root->left);
        if(hasprev && prev == root->val){
            currcount++;
        }
        else{
            currcount=1;
            hasprev = true;
        }
        if(currcount>maxcount){
            maxcount = currcount;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(currcount==maxcount){
            ans.push_back(root->val);
        }
        prev = root->val;
        solve(root->right);
    }
    // unordered_map<int, int>mp;
    // void storeFrequency(TreeNode* root){
    //     if(root == nullptr){
    //         return;
    //     }
    //     mp[root->val]++;
    //     storeFrequency(root->left);
    //     storeFrequency(root->right);
    // }
    vector<int> findMode(TreeNode* root) {
        // int maxFrequency=INT_MIN;
        // storeFrequency(root);
        // for(auto &e:mp){
        //     maxFrequency = max(maxFrequency, e.second);
        // }
        // vector<int>ans;
        // for(auto &e:mp){
        //     if(e.second == maxFrequency){
        //         ans.push_back(e.first);
        //     }
        // }
        // return ans;
        solve(root);
        return ans;
    }
};