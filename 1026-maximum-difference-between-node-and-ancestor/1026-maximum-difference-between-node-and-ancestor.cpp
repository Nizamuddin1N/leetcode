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
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ans = 0;
        queue<tuple<TreeNode*, int, int>>q;
        q.push({root, root->val, root->val});
        while(!q.empty()){
            auto [node, minValue, maxValue] = q.front();
            q.pop();
            ans = max(ans, abs(node->val-minValue));
            ans = max(ans, abs(node->val-maxValue));
            maxValue = max(maxValue, node->val);
            minValue = min(minValue, node->val);
            if(node->left){
                q.push({node->left, minValue, maxValue});
            }
            if(node->right){
                q.push({node->right, minValue, maxValue});
            }
        }
        return ans;
    }
};