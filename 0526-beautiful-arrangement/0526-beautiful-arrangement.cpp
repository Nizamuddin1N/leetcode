class Solution {
public:
    int ans;
    void recursive(int index, vector<bool>&used, int n){
        if(index > n){
            ans++;
            return;
        }
        for(int i=1; i<=n; i++){
            if(used[i]){
                continue;
            }
            if(i % index == 0 || index % i == 0){
                used[i] = true;
                recursive(index+1, used, n);
                used[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        ans = 0;
        vector<bool>used(n+1, false);
        recursive(1, used, n);
        return ans;
    }
};