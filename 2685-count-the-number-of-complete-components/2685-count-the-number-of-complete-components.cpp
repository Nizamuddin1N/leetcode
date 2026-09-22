class Solution {
public:
    //
    vector<bool>visited;
    bool bfs(int vertice, unordered_map<int, list<int>>&mp){
        if(visited[vertice]){
            return false;
        }
        queue<int>q;
        visited[vertice] = true;
        q.push(vertice);
        int vertex=0;
        int edge = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vertex++;
            edge +=mp[node].size();
            for(int x:mp[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        edge /= 2;
        return edge == vertex*(vertex-1)/2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>>map;
        visited.assign(n, false);
        for(auto& row : edges){
            map[row[0]].push_back(row[1]);
            map[row[1]].push_back(row[0]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(bfs(i, map)){
                    ans++;
                }
            }
        }
        return ans;
    }
};