class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1)
            return 1;
        vector<long long> dp(n + 1, 0);
        vector<long long> gap(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * gap[i - 1]) % MOD;
            gap[i] = (gap[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
};