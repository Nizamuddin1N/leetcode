class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
        dp[0][0]=1;
        int MOD = 1e9+7;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                if(j>0){
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
                }
                if(j>=i){
                    dp[i][j] = (dp[i][j]-dp[i-1][j-i] + MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};