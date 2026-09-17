class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long ans = 1;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    long long nCr(int n, int r) {

        if (r > n - r)
            r = n - r;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= r; i++) {
            numerator = (numerator * (n - r + i)) % MOD;
            denominator = (denominator * i) % MOD;
        }

        // numerator / denominator
        // = numerator * inverse(denominator)
        return (numerator * power(denominator, MOD - 2)) % MOD;
    }

    void solve(vector<int>& nums) {

        if (nums.size() <= 2)
            return;

        int root = nums[0];

        vector<int> left;
        vector<int> right;

        // Step 1: divide into left and right
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        int n = left.size();
        int m = right.size();

        // Step 2: arrange left and right
        long long ways = nCr(n + m, n);

        ans = (ans * ways) % MOD;

        // Step 3: recursively do the same thing
        solve(left);
        solve(right);
    }

    int numOfWays(vector<int>& nums) {

        solve(nums);

        // Original arrangement is also counted
        return (ans - 1 + MOD) % MOD;
    }
};