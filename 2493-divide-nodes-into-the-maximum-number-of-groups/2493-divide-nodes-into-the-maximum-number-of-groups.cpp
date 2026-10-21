class Solution {
public:
    vector<int>parent;
    int findingParent(vector<int>& parent, int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findingParent(parent, parent[x]);
    }

    bool unite(vector<int>&rank, int u, int v){
        int pu = findingParent(parent, u);
        int pv = findingParent(parent, v);
        if(pu == pv){
            return false;
        }
        if(rank[pu]<rank[pv]){
            swap(pu, pv);
        }
        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
    bool isBipartite(int n, vector<vector<int>>&graph){
        vector<int>color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                queue<int>q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int neigh:graph[node]){
                        if(color[neigh] == -1){
                            color[neigh] = 1-color[node];
                            q.push(neigh);
                        }
                        else if(color[neigh] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    //max group for each node;
    vector<int>maxgrouparr;
    int maxgroup;

    int bfs(int start, vector<vector<int>>&graph, int n){
        vector<int>dist(n+1, -1);
        int level = 0;
        queue<int>q;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int node = q.front();
                q.pop();
                for(int neigh:graph[node]){
                    if(dist[neigh] == -1){
                        dist[neigh] = dist[node]+1;
                        q.push(neigh);
                    }
                }
            }
            level++;   
        }
        return level;
    }
    void dfs(int start, int dist, vector<vector<int>>&graph, vector<bool>&visited){
        if(visited[start]){
            maxgroup = max(maxgroup, dist);
            return;
        }
        visited[start] = true;
        if(graph[start].empty()){
            maxgroup = max(maxgroup, dist+1);
        }
        for(int neigh:graph[start]){
            dfs(neigh, dist++, graph, visited);
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int group = 0;
        vector<vector<int>>graph(n+1);
        maxgrouparr.assign(n+1, 0);
        parent.assign(n+1, 0);
        iota(parent.begin(), parent.end(), 0);
        vector<int>rank(n+1, 1);
        for(auto&edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            unite(rank, u, v);
        }
        if(!isBipartite(n, graph)){
            return -1;
        }
        for(int i=1; i<=n; i++){
            int root = findingParent(parent, i);
            int group = bfs(i, graph, n);
            maxgrouparr[root] = max(maxgrouparr[root], group);
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(findingParent(parent, i) == i){
                ans += maxgrouparr[i];
            }
        }
        return ans;
        // for(int i=1; i<=n; i++){
        //     maxgroup = INT_MIN;
        //     vector<bool>visited(n+1, false);
        //     dfs(i, 0, graph, visited);
        //     maxgrouparr[i] = maxgroup;
        // }

        // int ans = 0;
        // for(int i=1; i<=n; i++){
        //     ans = max(ans, maxgrouparr[i]);
        //     for(int j=i+1; j<=n; j++){
        //         if(unite(rank, i, j)){
        //             ans = max(ans, maxgrouparr[i]+maxgrouparr[j]);
        //         }
        //     }
        // }
        // return ans;
    }
};