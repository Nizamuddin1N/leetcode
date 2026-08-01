class Solution {
public:
    vector<bool> checkelement;
    int target;
    int l;
    bool recursive(int side, int index, int sum, vector<int>& nums){
        if(side == l-1){
            return true;
        }
        if(sum == 0){
            return recursive(side+1, 0, target, nums);
        }
        for(int i= index; i<nums.size(); i++){
            if(checkelement[i]){
                continue;
            }
            if(nums[i] > sum){
                continue;
            }
            checkelement[i] = true;
            if (recursive(side, i + 1, sum - nums[i], nums))
                return true;
            checkelement[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum = 0;
        l=k;
        for (int x : nums)
            totalsum += x;
        if (totalsum % k != 0)
            return false;
        target = totalsum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        checkelement.assign(nums.size(), false);
        return recursive(0, 0, target, nums);
    }
};