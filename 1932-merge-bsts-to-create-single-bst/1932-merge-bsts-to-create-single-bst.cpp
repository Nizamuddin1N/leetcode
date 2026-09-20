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
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> used;

    bool dfs(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        if (node->val <= low || node->val >= high)
            return false;

        if (!node->left && !node->right && mp.count(node->val)) {
            TreeNode* t = mp[node->val];

            if (t != node) {
                used.insert(node->val);
                node->left = t->left;
                node->right = t->right;
            }
        }

        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        mp.clear();
        used.clear();

        for (TreeNode* root : trees)
            mp[root->val] = root;

        unordered_set<int> leaves;

        for (TreeNode* root : trees) {
            if (root->left)
                leaves.insert(root->left->val);

            if (root->right)
                leaves.insert(root->right->val);
        }

        TreeNode* root = nullptr;

        for (TreeNode* node : trees) {
            if (!leaves.count(node->val)) {
                if (root != nullptr)
                    return nullptr;

                root = node;
            }
        }

        if (!root)
            return nullptr;

        used.insert(root->val);

        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;

        if (used.size() != trees.size())
            return nullptr;

        return root;
    }
};