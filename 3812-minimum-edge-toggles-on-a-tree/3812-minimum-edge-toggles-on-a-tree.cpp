class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> ans;
    string start, target;
    int dfs(int node, int parent) {
        int need = (start[node] != target[node]);
        for(auto &neigh : graph[node]) {
            int child = neigh.first;
            int edge = neigh.second;
            if(child == parent) {
                continue;
            }
            if(dfs(child, node)) {
                ans.push_back(edge);
                need ^= 1;
            }
        }
        return need;
    }

    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        this->start = start;
        this->target = target;
        graph.assign(n, {});
        ans.clear();
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back({v, i});
            graph[v].push_back({u, i});
        }
        if(dfs(0, -1)) {
            return {-1};
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};