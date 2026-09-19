class Solution {
public:
    vector<int> inordervalue;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);
        inordervalue.push_back(root->val);
        inorder(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<vector<int>> ans(queries.size());

        int i = 0;
        int n = inordervalue.size();

        for (auto &[query, index] : q) {
            while (i < n && inordervalue[i] < query) {
                i++;
            }

            int floorValue = -1;
            int ceilValue = -1;

            if (i < n) {
                ceilValue = inordervalue[i];
            }

            if (i < n && inordervalue[i] == query) {
                floorValue = inordervalue[i];
            }
            else if (i > 0) {
                floorValue = inordervalue[i - 1];
            }

            ans[index] = {floorValue, ceilValue};
        }

        return ans;
    }
};