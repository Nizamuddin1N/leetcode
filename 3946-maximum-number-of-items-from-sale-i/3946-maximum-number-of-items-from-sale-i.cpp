class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>frees(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j &&(items[j][0] % items[i][0]) == 0){
                    frees[i]++;
                }
            }
        }
        vector<int>dp(budget+1, 0);
        for(int i=0; i<n; i++){
            int cost = items[i][1];
            int free = frees[i];

            for(int j=budget; j>=cost; --j){
                dp[j] = max(dp[j], dp[j-cost] + 1 + free);
            }
            for(int j=cost; j<=budget; ++j){
                dp[j] = max(dp[j], dp[j-cost]+1);
            }
        }
        return dp[budget];
    }
};