class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>ans(n, 0);
        unordered_map<int, list<int>>adjList;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};