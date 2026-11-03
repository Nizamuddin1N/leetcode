class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int ans=0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[i][j]==1){
        //             dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]})+1;
        //             ans += dp[i+1][j+1];
        //         }
        //     }
        // }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    if(i-1>=0 && j-1>=0){
                        matrix[i][j] = min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]})+1;
                    }
                    else{
                        matrix[i][j] = 1;
                    }
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};