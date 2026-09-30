class Solution {
public:
    //dfs
    int answer = INT_MAX;
    int lastnode;
    void dfs(int node, vector<bool>&visited, vector<vector<pair<int, int>>>&graph, vector<int>&minCost, int cost){
        if(visited[node]){
            return;
        }
        if(cost>=minCost[node]){
            return;
        }
        minCost[node] = cost;
        if(node==lastnode){
            answer = min(answer, cost);
            return;
        }
        visited[node] = true;
        for(auto edge:graph[node]){
            dfs(edge.first, visited, graph, minCost, cost+edge.second);
        }
        visited[node] = false;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();//row
        int n = grid[0].size();//col
        int number = 0;
        vector<vector<pair<int, int>>>graph(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int row = i;
                int col = j;
                if(col-1 <= n-1 && col-1>=0){
                    if(grid[row][col] ==2){
                        graph[number].push_back({number-1, 0});
                    }
                    else{
                        graph[number].push_back({number-1, 1});
                    }
                }
                if(row+1>=0 && row+1<=m-1){
                    if(grid[row][col] == 3){
                        graph[number].push_back({number+n, 0});
                    }
                    else{
                        graph[number].push_back({number+n, 1});
                    }
                }
                if(col+1<=n-1 && col+1>=0){
                    if(grid[row][col] == 1){
                        graph[number].push_back({number+1, 0});
                    }
                    else{
                        graph[number].push_back({number+1, 1});
                    }
                }
                if(row-1>=0 && row-1<=m-1){
                    if(grid[row][col] == 4){
                        graph[number].push_back({number-n, 0});
                    }
                    else{
                        graph[number].push_back({number-n, 1});
                    }
                }
                number++;
            }
        }
        vector<int> dist(m * n, INT_MAX);

        deque<int> dq;

        dist[0] = 0;
        dq.push_front(0);

        while(!dq.empty()){

            int node = dq.front();
            dq.pop_front();

            for(auto edge : graph[node]){

                int neighbour = edge.first;
                int cost = edge.second;

                if(dist[node] + cost < dist[neighbour]){

                    dist[neighbour] = dist[node] + cost;

                    if(cost == 0){
                        dq.push_front(neighbour);
                    }
                    else{
                        dq.push_back(neighbour);
                    }
                }
            }
        }

        return dist[m * n - 1];

    }
};