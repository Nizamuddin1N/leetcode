class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high){
        vector<int>ans;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(nums[j]);
            j++;
        }
        int k=0;
        for(int x=low; x<=high; x++){
            nums[x] = ans[k];
            k++;
        }
    }
    void mergsort(vector<int>&nums, int low, int high){
        if(low<high){
            int mid = low + (high-low)/2;
            mergsort(nums, low, mid);
            mergsort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergsort(nums, 0, nums.size()-1);
        return nums;
    }
};