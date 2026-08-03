class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back(make_pair(v, w));
        }
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        dist[src][0] = 0;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int node = cur[1];
            int edges = cur[2];
            if (node == dst)
                return cost;
            if (edges == k + 1)
                continue;
            for (auto &nbr : adj[node]) {
                int next = nbr.first;
                int wt = nbr.second;
                if (cost + wt < dist[next][edges + 1]) {
                    dist[next][edges + 1] = cost + wt;
                    pq.push({cost + wt, next, edges + 1});
                }
            }
        }
        return -1;
    }
};