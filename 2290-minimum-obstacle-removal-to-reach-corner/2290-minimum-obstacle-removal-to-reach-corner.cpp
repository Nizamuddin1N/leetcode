class Solution {
public:
    // using 0-1 BF
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>>dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        while(!dq.empty()){
            auto[row, col] = dq.front();
            dq.pop_front();
            for(int d=0; d<4; d++){
                int nr = row+dr[d];
                int nc = col+dc[d];
                if(nr<0 || nr>=m || nc<0 || nc>=n){
                    continue;
                }
                if(dist[row][col]+grid[nr][nc]<dist[nr][nc]){
                    dist[nr][nc] = dist[row][col]+grid[nr][nc];
                    if(grid[nr][nc] == 0){
                        dq.push_front({nr, nc});
                    }
                    else{
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};