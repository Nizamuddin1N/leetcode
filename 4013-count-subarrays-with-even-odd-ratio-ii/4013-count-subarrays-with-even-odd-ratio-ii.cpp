class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> E(n+1, 0), O(n+1, 0), f(n+1);
        for (int i = 0; i < n; i++) {
            E[i+1] = E[i] + (nums[i] % 2 == 0);
            O[i+1] = O[i] + (nums[i] % 2 != 0);
        }
        for (int k = 0; k <= n; k++)
            f[k] = (long long)E[k]*b - (long long)a*O[k];
        vector<long long> sf(f);
        sort(sf.begin(), sf.end());
        sf.erase(unique(sf.begin(), sf.end()), sf.end());
        int m = sf.size();
        vector<int> bit(m+1, 0);
        auto update = [&](int pos){ for(++pos; pos<=m; pos += pos&(-pos)) bit[pos]++; };
        auto query = [&](int pos)->int{
            int res=0;
            for(++pos; pos>0; pos -= pos&(-pos)) res += bit[pos];
            return res;
        };
        long long ans = 0;
        int inserted = 0;
        int p = -1;

        for (int j = 0; j < n; j++) {
            if (nums[j] % 2 != 0) p = j;

            while (inserted <= p) {
                int idx = lower_bound(sf.begin(), sf.end(), f[inserted]) - sf.begin();
                update(idx);
                inserted++;
            }
            if (p == -1) continue;

            long long target = f[j+1];
            int idx = lower_bound(sf.begin(), sf.end(), target) - sf.begin();
            int lessCount = (idx == 0) ? 0 : query(idx-1);
            ans += inserted - lessCount;
        }
        return ans;
    }
};