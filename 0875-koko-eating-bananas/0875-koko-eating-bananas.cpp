class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxK = *max_element(piles.begin(), piles.end());
        int minK = 1;
        int ans = maxK;
        while(minK <= maxK){
            int mid = minK + (maxK-minK)/2;
            long long times = 0;
            for(int i=0; i<n; i++){
                times += (long long)(piles[i] + mid - 1) / mid;
            }
            if(times <= h){
                ans = mid;
                maxK = mid-1;
            }
            else{
                minK = mid+1;
            }
        }
        return ans;
    }
};