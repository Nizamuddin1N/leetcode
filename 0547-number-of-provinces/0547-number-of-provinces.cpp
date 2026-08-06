class Solution {
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited){
        stack<int>st;
        st.push(node);
        visited[node] = true;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(int i=0; i<isConnected[top].size(); i++){
                if(isConnected[top][i] != 0 && visited[i]==false){
                    visited[i] = true;
                    st.push(i);

                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans=0;
        vector<bool>visited(n , false);
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        return ans;
    }
};