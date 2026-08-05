class Solution {
public:
    //int A carry dynamic soup for A and int B carry dynamic soup for B
    double solve(int A, int B, vector<vector<double>>&dp){
        if(A<=0 && B<=0){
            return 0.5;
        }
        if(A<=0){
            return 1.0;
        }
        if(B<=0){
            return 0.0;
        }
        if(dp[A][B] != -1.0){
            return dp[A][B];
        }
        return dp[A][B] = 0.25*(solve(A-4, B, dp) + solve(A-3, B-1, dp) + solve(A-2, B-2, dp) + solve(A-1, B-3, dp));
    }
    double soupServings(int n) {
        if(n>=4800){
            return 1.0;
        }
        n = (n+24)/25;
        vector<vector<double>>dp(n+1, vector<double>(n+1, -1.0));
        return solve(n, n, dp);
    }
};