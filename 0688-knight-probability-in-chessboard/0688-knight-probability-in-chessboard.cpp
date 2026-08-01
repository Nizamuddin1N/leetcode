class Solution {
public:
    vector<pair<int, int>> dir = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    vector<vector<vector<double>>> dp;

    double solve(int n, int k, int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n)
            return 0.0;
        if (k == 0)
            return 1.0;
        if (dp[k][row][col] != -1.0)
            return dp[k][row][col];

        double probability = 0.0;

        for (auto &d : dir) {
            probability += solve(n, k - 1, row + d.first, col + d.second) / 8.0;
        }

        return dp[k][row][col] = probability;
    }

    double knightProbability(int n, int k, int row, int column) {

        dp.assign(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));

        return solve(n, k, row, column);
    }
};