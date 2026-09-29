class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        vector<bool>visited(n, false);
        int totalcost = 0;
        int totaledges = 0;
        pq.push({0, 0});
        while(!pq.empty() && totaledges<n){
            auto[w, node] = pq.top();
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node] = true;
            totalcost += w;
            totaledges++;
            for(auto& edge:adj[node]){
                int nextnode = edge.first;
                int nextweight = edge.second;
                if(!visited[nextnode]){
                    pq.push({nextweight, nextnode});
                }
            }
        }
        return totalcost;
    }
};