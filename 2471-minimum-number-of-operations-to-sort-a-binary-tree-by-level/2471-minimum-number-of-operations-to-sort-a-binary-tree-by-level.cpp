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
    int minswap(vector<int>level){
        int n = level.size();
        vector<pair<int, int>>mp;
        for(int i=0; i<n; i++){
            mp.push_back({level[i], i});
        }
        sort(mp.begin(), mp.end());
        vector<bool>visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || mp[i].second == i)
                continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = mp[j].second;
                cycleSize++;
            }
            swaps += cycleSize - 1;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
        int swap=0;
        queue<TreeNode*>q;
        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
        vector<int>level;
        while(!q.empty()){
            int n = q.size();
            level.clear();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            swap += minswap(level);
        }
        return swap;
    }
};