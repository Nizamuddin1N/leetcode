class Solution {
public:
    vector<int> ans;
    void merge(vector<pair<int, int>>&arr, int low, int mid, int high){
        vector<pair<int, int>> temp;
        int i=low;
        int j= mid+1;
        int rightCount = 0;
        while(i<= mid && j<=high){
            if(arr[j].first < arr[i].first){
                rightCount++;
                temp.push_back(arr[j]);
                j++;
            }
            else{
                ans[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            ans[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j++]);
        }
        for(int k=0; k<temp.size(); k++){
            arr[low+k] = temp[k];
        }
    }
    void mergeSort(vector<pair<int, int>>& arr, int low, int high){
        if(low >= high){
            return;
        }
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        vector<pair<int, int>>arr;
        for(int i=0; i<n; i++){
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, 0, n-1);
        return ans;
    }
};