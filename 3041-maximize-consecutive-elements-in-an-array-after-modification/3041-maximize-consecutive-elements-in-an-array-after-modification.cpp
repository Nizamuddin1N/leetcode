class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        // if(nums.size()==1){
        //     return 1;
        // }
        // int maxElement = *max_element(nums.begin(), nums.end());
        // vector<vector<int>>dp(maxElement+1, vector<int>(2, 0));
        sort(nums.begin(), nums.end());
        // for(int num:nums){
        //     dp[num][0] = 1;
        //     dp[num][1] = 1;
        // }
        // int ans=1;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]-nums[i-1] == 1 || (nums[i]) - (nums[i-1]+1) == 1){
        //         dp[nums[i]][0]++;
        //         ans = max(ans, dp[nums[i]][0]);
        //     }
        //     else if((nums[i]+1) - nums[i-1] == 1 || (nums[i]+1) - (nums[i-1]+1) == 1){
        //         dp[nums[i]][1]++;
        //         ans = max(ans, dp[nums[i]][0]);
        //     }
        // }
        // return ans;
        unordered_map<int, int>dp;
        int ans=0;
        for(int num:nums){
            dp[num+1] = dp[num]+1;
            dp[num] = dp[num-1]+1;
            ans = max({ans, dp[num+1], dp[num]}); 
        }
        return ans;
    }
};