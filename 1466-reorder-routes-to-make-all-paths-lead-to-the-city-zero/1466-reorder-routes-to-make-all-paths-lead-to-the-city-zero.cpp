
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        vector<bool> visited(n, false);
        int changes = 0;
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto [v, cost] : adj[u]) {
                if (visited[v])
                    continue;
                changes += cost;
                dfs(v);
            }
        };
        dfs(0);
        return changes;
    }
};
