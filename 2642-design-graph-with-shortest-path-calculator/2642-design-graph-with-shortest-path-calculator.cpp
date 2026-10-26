class Graph {
public:
    vector<vector<pair<int, int>>>graph;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        for(auto& edge:edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dist[node1] = 0;
        pq.push({0, node1});
        while(!pq.empty()){
            auto[weight, node] = pq.top();
            pq.pop();
            if(weight > dist[node]) continue;
            for(auto& edge:graph[node]){
                if(dist[node] + edge.second < dist[edge.first]){
                    dist[edge.first] = dist[node] + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        return dist[node2] == INT_MAX? -1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */