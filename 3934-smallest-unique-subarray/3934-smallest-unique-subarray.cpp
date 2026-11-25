class Solution {
public:
    using ll = long long;
    const ll mod = 1e9+7, base = 100003;
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<ll>h(n+1), p(n+1, 1);
        for(int i=0; i<n; i++){
            ll x = (nums[i] % mod + mod) % mod;
            h[i+1] = (h[i]*base + x)%mod;
            p[i+1] = (p[i]*base)%mod;
        }

        auto check = [&](int len){
            unordered_map<ll, int>mp;
            for(int i=0; i+len<=n; i++){
                ll hash = (h[i+len] - h[i]*p[len]%mod + mod)%mod;
                mp[hash]++;
            }
            for(auto it:mp){
                if(it.second == 1){
                    return true;
                }
            }
            return false;
        };
        int l=1, r=n, ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
        // int n = nums.size();
        // for(int i=1; i<=n; i++){
        //     map<vector<int>, int> mp;
        //     for(int j=0; j+i<=n; j++){
        //         vector<int>temp(nums.begin()+j, nums.begin()+j+i);
        //         mp[temp]++;
        //     }
        //     for(auto it:mp){
        //         if(it.second == 1){
        //             return i;
        //         }
        //     }
        // }
        // return -1;
    }
};