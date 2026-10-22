class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n, 0);
        vector<unordered_set<int>>graph(n);
        for(auto &road:roads){
            int u = road[0];
            int v = road[1];
            graph[u].insert(v);
            graph[v].insert(u);
            degree[u]++;
            degree[v]++;
        }
        int ans  = INT_MIN;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(graph[i].find(j) != graph[i].end() || graph[j].find(i) != graph[j].end()){
                    ans = max(ans, degree[i]+degree[j]-1);
                }
                else{
                    ans = max(ans, degree[i]+degree[j]);
                }
            }
        }
        return ans;
    }
};