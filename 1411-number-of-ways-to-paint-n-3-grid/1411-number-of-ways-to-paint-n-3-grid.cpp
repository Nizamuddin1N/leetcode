class Solution {
public:
    int numOfWays(int n) {
        long long same = 6;
        long long diff = 6;
        long long mod = 1e9 + 7;

        for(int i = 2; i <= n; i++) {
            long long newSame = (3 * same + 2 * diff) % mod;
            long long newDiff = (2 * same + 2 * diff) % mod;

            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % mod;
    }
};