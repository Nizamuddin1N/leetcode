
class Solution {
public:
    int ans = INT_MAX;
    int n = 0, m = 0;
    // vector<vector<int>> visited;

    // void solve(int row, int col, vector<vector<int>>& moveTime,
    //            int result) {
    //     if (row < 0 || row >= n || col < 0 || col >= m) {
    //         return;
    //     }

    //     if (result >= visited[row][col]) {
    //         return;
    //     }

    //     visited[row][col] = result;

    //     if (row == n - 1 && col == m - 1) {
    //         ans = min(ans, result);
    //         return;
    //     }

    //     int dr[] = {-1, 1, 0, 0};
    //     int dc[] = {0, 0, -1, 1};

    //     for (int i = 0; i < 4; i++) {
    //         int nr = row + dr[i];
    //         int nc = col + dc[i];

    //         if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
    //             int nextTime = max(result, moveTime[nr][nc]) + 1;

    //             if (nextTime < visited[nr][nc]) {
    //                 solve(nr, nc, moveTime, nextTime);
    //             }
    //         }
    //     }
    // }

    void solve(vector<vector<int>>& moveTime){
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!pq.empty()){
            auto [time, row, col] = pq.top();
            pq.pop();
            if(time != dist[row][col]){
                continue;
            }
            if(row == n-1 && col ==  m-1){
                ans = time;
                return;
            }
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nc <0 || nr >= n || nr <0 || nc >= m){
                    continue;
                }

                int nextTime = max(time, moveTime[nr][nc]) + 1;
                if(nextTime < dist[nr][nc]){
                    dist[nr][nc] = nextTime;
                    pq.push({nextTime, nr, nc});
                }
            }
        }

    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();
        ans = INT_MAX;
        solve(moveTime);
        return ans;
        // n = moveTime.size();
        // m = moveTime[0].size();
        // ans = INT_MAX;

        // visited.assign(n, vector<int>(m, INT_MAX));

        // solve(0, 0, moveTime, 0);

        // return ans;
    }
};
