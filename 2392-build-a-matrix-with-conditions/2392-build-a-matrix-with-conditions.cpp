class Solution {
public:
    vector<int> topologicalsort(int k, vector<vector<int>>& condition){
        vector<vector<int>>adj(k+1);
        vector<int>indegree(k+1, 0);
        for(auto& edge:condition){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>order;
        queue<int>q;
        for(int i=1; i<=k; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int next : adj[node]){
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if(order.size() != k){
            return {};
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalsort(k, rowConditions);
        vector<int> colOrder = topologicalsort(k, colConditions);
        if(rowOrder.empty() || colOrder.empty()){
            return {};
        }
        vector<int> row(k + 1);
        vector<int> col(k + 1);
        for (int i = 0; i < k; i++) {
            row[rowOrder[i]] = i;
            col[colOrder[i]] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int num = 1; num <= k; num++) {
            ans[row[num]][col[num]] = num;
        }
        return ans;
    }
};