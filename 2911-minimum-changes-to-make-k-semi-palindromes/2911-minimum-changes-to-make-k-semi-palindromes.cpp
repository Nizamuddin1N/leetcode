
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute cost for every substring
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int minCost = n;

                // Try every valid divisor
                for (int d = 1; d <= len/2; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Compare corresponding characters
                    // in each group to make it a palindrome
                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r]) {
                                changes++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    minCost = min(minCost, changes);
                }

                cost[i][j] = minCost;
            }
        }

        // dp[i][parts] = minimum changes needed
        // to divide first i characters into parts substrings
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {

                // Previous partition ends at h-1
                for (int h = 0; h < i; h++) {

                    int len = i - h;

                    // Every semi-palindrome must have length >= 2
                    if (len < 2) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[h][parts - 1] + cost[h][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
