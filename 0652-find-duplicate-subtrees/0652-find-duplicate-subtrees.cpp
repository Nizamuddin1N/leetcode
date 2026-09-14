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
    map<tuple<int,int,int>, int>mp;
    unordered_map<int, int>count;
    vector<TreeNode*>ans;
    int id = 1;
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        tuple<int, int, int>curr = {left, root->val, right};
        if(mp.count(curr) == 0){
            mp[curr] = id++;
        }
        int currId = mp[curr];
        count[currId]++;
        if(count[currId] == 2){
            ans.push_back(root);
        }
        return currId;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};