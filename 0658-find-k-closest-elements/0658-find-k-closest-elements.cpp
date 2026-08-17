class Solution {
public:
    vector<int> ans;
    void solve(vector<int>& arr, int low, int high, int mid, int k){
        while(low >= 0 && high < arr.size() && k != 0){
            k--;
            int leftcheck = abs(arr[low] - mid);
            int rightcheck = abs(arr[high] - mid);
            if (leftcheck == rightcheck) {
                ans.push_back(min(arr[low], arr[high]));
                if (arr[low] < arr[high])
                    low--;
                else
                    high++;
            }
            else if(leftcheck < rightcheck){
                ans.push_back(arr[low]);
                low--;
            }
            else{
                ans.push_back(arr[high]);
                high++;
            }
        }
        while(low >= 0 && k != 0){
            ans.push_back(arr[low]);
            low--;
            k--;
        }
        while(high < arr.size() && k != 0){
            ans.push_back(arr[high]);
            high++;
            k--;
        }
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int low = high-1;
        solve(arr, low, high, x, k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};