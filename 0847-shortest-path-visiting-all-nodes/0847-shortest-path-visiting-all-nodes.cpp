class Solution {
public:
    // bool isallvisited(vector<bool>&visited){
    //     for(bool node:visited){
    //         if(node == false){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int ans = INT_MAX;
    // void dfs(int currnode, int prevnode, vector<vector<int>>&graph, vector<bool>&visited, int path, unordered_map<int, int>mpprevnode){
    //     mpprevnode[currnode] = prevnode;
    //     if(isallvisited(visited)){
    //         ans = min(ans, path);
    //         return;
    //     }
    //     bool isdfs = true;
    //     for(int neigh:graph[currnode]){
    //         if(!visited[neigh]){
    //             isdfs = false;
    //         }
    //     }
    //     if(isdfs){
    //         dfs(prevnode, mpprevnode[prevnode], graph, visited, path+1, mpprevnode);
    //     }

    //     for(int neigh:graph[currnode]){
    //         if(!visited[neigh]){
    //             visited[neigh] = true;
    //             dfs(neigh, currnode, graph, visited, path+1, mpprevnode);
    //         }
    //     }

    // }
    int shortestPathLength(vector<vector<int>>& graph) {
        // int n = graph.size();
        // for(int i=0; i<n; i++){
        //     vector<bool>visited(n, false);
        //     visited[i] = true;
        //     unordered_map<int, int>mpprevnode;
        //     dfs(i, 0, graph, visited, 0, mpprevnode);
        // }
        // return ans;
        int n = graph.size();
        int target = (1<<n)-1;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n, vector<bool>(1<<n, false));
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            q.push({i, mask});
            visited[i][mask] = true;
        }
        int step=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[node, mask] = q.front();
                q.pop();
                if(mask == target){
                    return step;
                }
                for(int neigh:graph[node]){
                    int newmask = mask | (1<<neigh);
                    if(visited[neigh][newmask] == false){
                        visited[neigh][newmask] = true;
                        q.push({neigh, newmask});
                    }
                }
            }
            step++;
        }
        return 0;
    }
};