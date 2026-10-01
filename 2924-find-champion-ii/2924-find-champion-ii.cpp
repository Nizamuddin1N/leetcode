class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> freq(n, 0);

        for(auto edge : edges){
            freq[edge[1]]++;
        }
        int ans = -1;
        int count=0;
        for(int i = 0; i < n; i++){
            if(freq[i] == 0){
                ans = i;
                count++;
            }
        }
        if(count == 1){
            return ans;
        }
        return -1;
    }
};