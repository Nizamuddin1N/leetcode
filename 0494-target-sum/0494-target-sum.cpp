class Solution {
public:
    int ans=0;
    void recursive(vector<int>&nums, int target, int &sum, int index){
        if(index == nums.size()){
            if(sum == target){
                ans++;
            }
            return;
        }
        sum +=nums[index];
        recursive(nums, target, sum, index+1);
        sum -=nums[index];

        sum -=nums[index];
        recursive(nums, target, sum, index+1);
        sum +=nums[index];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        recursive(nums, target, sum, 0);
        return ans;
    }
};