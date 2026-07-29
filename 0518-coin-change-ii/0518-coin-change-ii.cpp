class Solution {
public:
    int recursive(int index, int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(amount <0){
            return 0;
        }
        if(index == coins.size()){
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int take = recursive(index, amount-coins[index], coins, dp);
        int skip = recursive(index+1, amount, coins, dp);
        dp[index][amount] = take + skip;
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return recursive(0, amount, coins, dp);
    }
};