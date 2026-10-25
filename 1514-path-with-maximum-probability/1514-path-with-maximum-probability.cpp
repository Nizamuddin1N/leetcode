class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dist(n, 0.0);
        vector<vector<pair<int, double>>>graph(n);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>>pq;
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            auto[d, u] = pq.top();
            pq.pop();
            if(d<dist[u]) continue;
            for(auto [v, wt]:graph[u]){
                if(dist[u] * wt>dist[v]){
                    dist[v] = dist[u] * wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[end_node];
    }
};