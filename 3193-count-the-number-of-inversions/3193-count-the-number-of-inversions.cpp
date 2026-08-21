class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9+7;
        vector<int>req(n, -1);
        int maxK = 0;
        for(auto &r:requirements){
            int end = r[0];
            int cnt = r[1];

            req[end] = cnt;
            maxK = max(maxK, cnt);
        }
        vector<vector<int>> dp(n+1, vector<int>(maxK+1, 0));
        dp[0][0] = 1;
            for(int i=1; i<=n; i++){
                for(int j=0; j<=maxK; j++){
                    for(int add=0; add <=i-1; add++){
                        if(j-add >=0){
                            dp[i][j] = (dp[i][j] + dp[i-1][j-add])%MOD;
                        }
                    }
                }
                int required = req[i-1];
                if(required != -1){
                    for(int j=0; j<=maxK; j++){
                        if(j!=required){
                            dp[i][j] = 0;
                        }
                    }
                }
            }
        return dp[n][req[n-1]];
    }
};