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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> nodes;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            nodes.push_back(node);

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        int ans = 0;

        for (TreeNode* start : nodes) {
            queue<pair<TreeNode*, int>> bfs;
            unordered_set<TreeNode*> visited;

            bfs.push({start, 0});
            visited.insert(start);

            while (!bfs.empty()) {
                auto [node, dist] = bfs.front();
                bfs.pop();

                ans = max(ans, dist);

                vector<TreeNode*> next = {
                    node->left,
                    node->right,
                    parent[node]
                };

                for (TreeNode* nextNode : next) {
                    if (nextNode &&
                        !visited.count(nextNode) &&
                        nextNode->val == start->val) {

                        visited.insert(nextNode);
                        bfs.push({nextNode, dist + 1});
                    }
                }
            }
        }

        return ans;
    }
};