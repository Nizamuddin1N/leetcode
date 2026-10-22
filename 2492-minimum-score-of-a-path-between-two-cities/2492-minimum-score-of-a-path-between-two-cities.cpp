class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // sort(roads.begin(), roads.end(), [&](vector<int>&road1, vector<int>& road2){
        //     return road1[2]<road2[2];
        // });
        // return roads[0][2];
        vector<vector<int>>matrix(n+1);
        for(auto& road:roads){
            matrix[road[0]].push_back(road[1]);
            matrix[road[1]].push_back(road[0]);
        }
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(1);
        unordered_set<int>st;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node]){
                continue;
            }
            st.insert(node);
            visited[node]= true;
            for(int neigh:matrix[node]){
                q.push(neigh);
            }
        }
        int ans = INT_MAX;
        for(auto&road:roads){
            if(st.find(road[0]) != st.end() && st.find(road[1]) != st.end()){
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};