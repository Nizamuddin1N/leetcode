
class Solution {
public:
    vector<int> bobTime;
    vector<int> temp;
    vector<bool> visited;
    vector<bool> visited2;
    int maximum = INT_MIN;
    vector<int> amount;

    void dfs1(int time, vector<vector<int>>& adj, int node) {
        visited[node] = true;
        temp[node] = time;

        if (node == 0) {
            bobTime = temp;
            return;
        }

        bool found = false;

        for (auto& neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs1(time + 1, adj, neigh), bobTime[neigh] != INT_MAX) {
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            temp[node] = INT_MAX;
        } else {
            bobTime[node] = time;
        }
    }

    void dfs2(int time, vector<vector<int>>& adj, int profit, int node, int parent = -1) {

        visited2[node] = true;
        if (time < bobTime[node]) {
            profit += amount[node];
        }
        else if (time == bobTime[node]) {
            profit += amount[node] / 2;
        }

        bool isLeaf = true;

        for (auto& neigh : adj[node]) {
            if (neigh == parent) continue;

            isLeaf = false;
            dfs2(time + 1, adj, profit, neigh, node);
        }

        if (isLeaf) {
            maximum = max(maximum, profit);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges,int bob, vector<int>& amount) {
        int n = amount.size();
        this->amount = amount;
        bobTime.assign(n, INT_MAX);
        temp.assign(n, INT_MAX);
        visited.assign(n, false);
        visited2.assign(n, false);
        maximum = INT_MIN;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs1(0, adj, bob);
        dfs2(0, adj, 0, 0);

        return maximum;
    }
};
