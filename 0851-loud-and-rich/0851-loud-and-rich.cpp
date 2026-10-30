class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>graph(n);
        for(auto&edge: richer){
            graph[edge[1]].push_back(edge[0]);
        }
        //trying
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int quietperson=i;
            vector<bool>visited(n, false);
            queue<int>q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int person = q.front();
                if(quiet[quietperson] > quiet[person]){
                    quietperson = person;
                }
                q.pop();
                for(int neigh:graph[person]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            ans[i] = quietperson;
        }
        return ans;
    }
};