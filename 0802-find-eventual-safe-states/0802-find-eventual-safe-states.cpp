class Solution {
public:
    bool dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&isTerminal){
        if(isTerminal[node]){
            return true;
        }
        if(visited[node]){
            return false;
        }
        visited[node] = true;
        bool path = true;
        for(int neighbour:graph[node]){
            path = path && dfs(neighbour, graph, visited, isTerminal);
        }
        if(path == true){
            isTerminal[node]=true;
        }
        return path;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>isTerminal(n, false);
        for(int i=0; i<n; i++){
            if(graph[i].empty()){
                isTerminal[i] = true;
            }
        }
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            dfs(i, graph, visited, isTerminal);
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(isTerminal[i] == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};