class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>dp(n, vector<int>(n, n));
        int ans=0;
        for(auto &m:mines){
            dp[m[0]][m[1]] = 0;
        }
        //left pass
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                count = (dp[i][j] == 0) ? 0 : count+1;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        //right pass
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=n-1; j>=0; j--){
                count = (dp[i][j] == 0) ? 0 : count+1;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        //down pass
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                count = (dp[j][i] == 0) ? 0 : count+1;
                dp[j][i] = min(dp[j][i], count);
            }
        }

        //up pass
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=n-1; j>=0; j--){
                count = (dp[j][i] == 0) ? 0 : count+1;
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};