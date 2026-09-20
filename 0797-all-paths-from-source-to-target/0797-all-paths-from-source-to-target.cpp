class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node, int destination, vector<vector<int>>& graph, vector<int>&visited){
        visited.push_back(node);
        if(node == destination){
            ans.push_back(visited);
            visited.pop_back();
            return;
        }
        for(int integer:graph[node]){
            if(find(visited.begin(), visited.end(), integer) == visited.end()){
                dfs(integer, destination, graph, visited);
            }
        }
        visited.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int destination = graph.size()-1;
        vector<int>visited;
        dfs(0, destination, graph, visited);
        return ans;
    }
};