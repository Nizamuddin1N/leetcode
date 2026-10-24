class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> subtree(n, 1);
        vector<int> ans(n, 0);
        function<void(int, int)> dfs1 = [&](int u, int parent) {
            for (int v : graph[u]) {
                if (v == parent) continue;

                dfs1(v, u);

                subtree[u] += subtree[v];
                ans[u] += ans[v] + subtree[v];
            }
        };

        dfs1(0, -1);
        function<void(int, int)> dfs2 = [&](int u, int parent) {
            for (int v : graph[u]) {
                if (v == parent) continue;

                ans[v] = ans[u] + n - 2 * subtree[v];

                dfs2(v, u);
            }
        };
        dfs2(0, -1);
        return ans;
    }
};
        // vector<int>ans(n);
        // vector<vector<int>>dist(n, vector<int>(n, 1e9));
        // for(int i = 0; i < n; i++){
        //     dist[i][i] = 0;
        // }
        // for(auto& edge:edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     dist[u][v] =1;
        //     dist[v][u] =1;
        // }
        // for(int k = 0; k<n; k++){
        //     for(int i=0; i<n; i++){
        //         for(int j=0; j<n; j++){
        //             if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
        //                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        //             }
        //         }
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     int answer = 0;
        //     for(int j=0; j<n; j++){
        //         if(dist[i][j] != 1e9){
        //             answer += dist[i][j];
        //         }
        //     }
        //     ans[i] = answer;
        // }
        // return ans;
        // for(int i=0; i<n; i++){
        //     queue<int>q;
        //     q.push(i);
        //     int level=0;
        //     int answer = 0;
        //     vector<bool>visited(n, false);
        //     while(!q.empty()){
        //         int sz = q.size();
        //         for(int i=0; i<sz; i++){
        //             int node = q.front();
        //             q.pop();
        //             if(visited[node]){
        //                 continue;
        //             }
        //             visited[node] = true;
        //             answer +=level;
        //             for(int neigh:graph[node]){
        //                 q.push(neigh);
        //             }
        //         }
        //         level++;
        //     }
        //     ans[i] = answer;
        // }
        // return ans;
