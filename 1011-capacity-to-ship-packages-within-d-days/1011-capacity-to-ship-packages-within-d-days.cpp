class Solution {
public:
    bool canship(vector<int>& weights, int days, int capacity){
        int current = 0;
        int countdays = 1;
        for(int w : weights){
            if(current+w>capacity){
                current = 0;
                countdays++;
            }
            current +=w;
        }
        return countdays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lowcap = *max_element(weights.begin(), weights.end());
        int maxcap = accumulate(weights.begin(), weights.end(), 0);
        int ans = maxcap;
        while(lowcap <= maxcap){
            int mid = lowcap + (maxcap-lowcap)/2;
            if(canship(weights, days, mid)){
                ans = mid;
                maxcap = mid-1;
            }
            else{
                lowcap = mid+1;
            }
        }
        return ans;
    }
};