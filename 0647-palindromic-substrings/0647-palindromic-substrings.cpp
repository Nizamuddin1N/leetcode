class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int gap = 0; gap < n; gap++){
            for(int i=0; i+gap < n; i++){
                int j = i+gap;
                if(gap==0){
                    dp[i][j] = 1;
                }
                else if(gap == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
                ans +=dp[i][j];
            }
        }
        return ans;
    }
};