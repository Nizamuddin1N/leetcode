class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>>cost(n, vector<int>(n, 0)); //cost[i][j] = minimum change to make s[i...j] a semi-palindrome 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                //precomputing cost for each substring
                int len = j-i+1;
                int minCost=n;
                for(int d=1; d<=len/2; d++){
                    if(len%d != 0) continue;
                    int changes = 0;
                    for(int offset=0; offset<d; offset++){
                        int l=i+offset;
                        int r = j-d+1+offset;
                        while(l<r){
                            if(s[l] != s[r]){
                                changes++;
                            }
                            l +=d;
                            r -=d;

                        }
                    }
                    minCost = min(minCost, changes);
                }
                cost[i][j] = minCost;
            }
        }
        const int INF = 1e9;
        vector<vector<int>>dp(n+1, vector<int>(k+1, INF));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int part = 1; part<=k; part++){
                for(int h=0; h<i; h++){
                    int len = i-h;
                    if(len<2) continue;
                    dp[i][part] = min(dp[i][part], dp[h][part-1]+cost[h][i-1]);
                }
            }
        }
        return dp[n][k];
    }
};