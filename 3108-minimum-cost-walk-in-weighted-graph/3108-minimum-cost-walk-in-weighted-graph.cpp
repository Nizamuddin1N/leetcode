
class Solution {
public:
    vector<int> parent, sz, cost;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
        cost[u] &= cost[v];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        sz.assign(n, 1);
        cost.assign(n, -1);

        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];

            int ru = find(u);
            int rv = find(v);

            if (ru != rv) {
                unite(ru, rv);
            }

            int root = find(u);
            cost[root] &= w;
        }

        vector<int> ans;

        for (auto& q : query) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
            } else if (find(u) != find(v)) {
                ans.push_back(-1);
            } else {
                ans.push_back(cost[find(u)]);
            }
        }

        return ans;
    }
};
