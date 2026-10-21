class Solution {
public:
    // int ans=INT_MIN;
    // void dfs(int start, vector<vector<int>>&graph, unordered_map<int, int>&outdegree, int month, vector<int>&time, vector<int>&visited){
    //     if(outdegree[start] == 0){
    //         ans = max(ans, month+time[start-1]);
    //         return;
    //     }
    //     for(int neigh:graph[start]){
    //         if(!visited[neigh]){
    //             visited[neigh] = true;
    //             dfs(neigh, graph, outdegree, month + time[start-1], time, visited);
    //         }
    //     }
    // }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, int>indegree(n+1);
        // unordered_map<int, int>outdegree(n+1);
        vector<vector<int>>graph(n+1);
        for(auto &relation:relations){
            int u = relation[0];
            int v = relation[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        vector<int>dp(n+1, 0);
        queue<int>q;
        for(int i=1; i<=n; i++){
            dp[i] = time[i-1];
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int ans =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans = max(ans, dp[node]);
            for(int neigh:graph[node]){
                dp[neigh] = max(dp[neigh], dp[node] + time[neigh-1]);
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        return ans;

        // for(int i=1; i<=n; i++){
        //     if(indegree[i] == 0){
        //         vector<int>visited(n+1, false);
        //         visited[i] = true;
        //         dfs(i, graph, outdegree, 0, time, visited);
        //     }
        // }
        // return ans;
        //using kahn's algorithm

    }
};