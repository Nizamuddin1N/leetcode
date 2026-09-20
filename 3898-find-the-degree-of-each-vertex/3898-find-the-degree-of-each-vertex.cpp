class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_map<int, list<int>>adjList;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = adjList[i].size();
        }
        return ans;
    }
};