class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto &m:mines){
            grid[m[0]][m[1]] = 0;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                int d=1;
                while(true){
                    if(i-d <0 || j-d <0 || i+d >=n || j+d >= n){
                        break;
                    }
                    if(grid[i-d][j] == 0 || grid[i+d][j] == 0 || grid[i][j-d] == 0|| grid[i][j+d]==0){
                        break;
                    }
                    d++;
                }
                ans = max(ans, d);
            }
        }
        return ans;
    }
};