/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>mp;
    void parentOfEach(TreeNode* root, TreeNode* parent){
        if(root == nullptr){
            return;
        }
        mp[root] = parent;
        parentOfEach(root->left, root);
        parentOfEach(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root ==  nullptr){
            return {};
        }
        parentOfEach(root, nullptr);
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k){
                vector<int>ans;
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }           
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(mp[node] && !visited.count(mp[node])){
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            dist++;
        }
        return {};
    }
};