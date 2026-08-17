class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // if(nums.size() == 1){
        //     return nums[0];
        // }
        // for(int i=0; i<nums.size();){
        //     if(nums[i] != nums[i+1] || i+1 == nums.size()){
        //         return nums[i];
        //     }
        //     i=i+2;
        // }
        // return -1;

        // int low = 0;
        // int high = nums.size()-1;
        // while(low<=hight){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid]!= nums[mid-1] && nums[mid] != nums[mid+1]){
        //         return nums[mid];
        //     }
        //     if(high-mid % 2 == 0 && nums[mid]==nums[mid+1]){
        //         low = mid+1;
        //     }
        //     else if(high-mid % 2 !=0 && nums[mid] != nums[mid+1]){
        //         low = mid+1;
        //     }
        //     else{
        //         high = mid-1;
        //     }
        // }
        // return -1;
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(mid %2 != 0){
                mid--;
            }
            if(nums[mid] == nums[mid+1]){
                low = mid+2;
            }
            else{
                high = mid;
            }
        }
        return nums[high];
    }
};