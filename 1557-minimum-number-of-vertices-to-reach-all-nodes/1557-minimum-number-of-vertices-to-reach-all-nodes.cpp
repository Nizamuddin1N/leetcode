class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isincoming(n, false);
        vector<int>ans;
        for(auto& edge:edges){
            isincoming[edge[1]] = true;
        }
        for(int i=0; i<n; i++){
            if(isincoming[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};