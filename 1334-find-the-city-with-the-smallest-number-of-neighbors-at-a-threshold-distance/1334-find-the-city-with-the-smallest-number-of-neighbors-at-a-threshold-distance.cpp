class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //make adjacency list;
        vector<vector<pair<int,int>>>adjacency(n);
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjacency[u].push_back({v,w});
            adjacency[v].push_back({u,w});
        }
        int answer = -1;
        int mincount = INT_MAX;
        for(int src=0; src<n; src++){
            vector<int>dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            dist[src] = 0;
            pq.push({0, src});
            while(!pq.empty()){
                auto[d, node] = pq.top();
                pq.pop();
                if(d>dist[node]){
                    continue;
                }
                for(auto&edge:adjacency[node]){
                    int next = edge.first;
                    int weight = edge.second;
                    int newdist = d + weight;
                    if(newdist < dist[next]){
                        dist[next] = newdist;
                        pq.push({newdist, next});
                    }
                }
            }
            int count = 0;
            for(int i=0; i<n; i++){
                if(i != src && dist[i] <= distanceThreshold){
                    count++;
                }
            }
            if(count<=mincount){
                mincount = count;
                answer = src;
            }
        }
        return answer;
    }
};