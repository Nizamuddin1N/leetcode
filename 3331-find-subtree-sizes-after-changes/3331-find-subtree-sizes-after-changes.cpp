
// class Solution {
// public:
//     vector<int> findSubtreeSizes(vector<int>& parent, string s) {
//         int n = parent.size();

//         vector<vector<int>> adj(n), tree(n);

//         for(int i = 1; i < n; i++) {
//             adj[parent[i]].push_back(i);
//         }

//         vector<int> last(26, -1);
//         vector<int> newParent(n, -1);

//         function<void(int)> dfs1 = [&](int u) {
//             int ch = s[u] - 'a';
//             int prev = last[ch];

//             for(int v : adj[u]) {
//                 int c = s[v] - 'a';

//                 newParent[v] = (last[c] != -1) ? last[c] : u;

//                 dfs1(v);
//             }

//             last[ch] = u;
//         };

//         dfs1(0);

//         for(int i = 1; i < n; i++) {
//             tree[newParent[i]].push_back(i);
//         }

//         vector<int> ans(n);

//         function<int(int)> dfs2 = [&](int u) {
//             ans[u] = 1;

//             for(int v : tree[u]) {
//                 ans[u] += dfs2(v);
//             }

//             return ans[u];
//         };

//         dfs2(0);

//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     vector<vector<int>> adj, tree;
// //     vector<int> last, newParent, ans;
// //     string s;

// //     void dfs1(int u) {
// //         int ch = s[u] - 'a';

// //         for(int v : adj[u]) {
// //             int c = s[v] - 'a';

// //             newParent[v] = (last[c] != -1) ? last[c] : u;

// //             dfs1(v);
// //         }

// //         last[ch] = u;
// //     }

// //     int dfs2(int u) {
// //         ans[u] = 1;

// //         for(int v : tree[u]) {
// //             ans[u] += dfs2(v);
// //         }

// //         return ans[u];
// //     }

// //     vector<int> findSubtreeSizes(vector<int>& parent, string str) {
// //         int n = parent.size();
// //         s = str;

// //         adj.resize(n);
// //         tree.resize(n);
// //         last.assign(26, -1);
// //         newParent.resize(n);
// //         ans.resize(n);

// //         for(int i = 1; i < n; i++) {
// //             adj[parent[i]].push_back(i);
// //         }

// //         dfs1(0);

// //         for(int i = 1; i < n; i++) {
// //             tree[newParent[i]].push_back(i);
// //         }

// //         dfs2(0);

// //         return ans;
// //     }
// // };

class Solution {
public:
    vector<vector<int>> adj, tree;
    vector<int> last, newParent, ans;
    string s;

    void dfs1(int u) {
        int ch = s[u] - 'a';
        int prev = last[ch];

        last[ch] = u;

        for(int v : adj[u]) {
            int c = s[v] - 'a';

            newParent[v] = (last[c] != -1) ? last[c] : u;

            dfs1(v);
        }

        last[ch] = prev;
    }

    int dfs2(int u) {
        ans[u] = 1;

        for(int v : tree[u]) {
            ans[u] += dfs2(v);
        }

        return ans[u];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        adj.resize(n);
        tree.resize(n);
        last.assign(26, -1);
        newParent.resize(n);
        ans.resize(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs1(0);

        for(int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        dfs2(0);

        return ans;
    }
};

