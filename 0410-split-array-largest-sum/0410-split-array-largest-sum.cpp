class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int part=1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i]>mid){
                part++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return part<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};