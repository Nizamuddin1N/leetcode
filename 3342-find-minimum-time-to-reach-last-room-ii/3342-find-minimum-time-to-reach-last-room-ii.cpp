class Solution {
public:
    int ans = 0;
    int n = 0, m=0;
    void solve(vector<vector<int>>& moveTime) {
        vector<vector<vector<int>>>dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>pq;
        dist[0][0][0]=0;
        pq.push({0, 0, 0, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!pq.empty()){
            auto [time, row, col, state] = pq.top();
            pq.pop();
            if(time != dist[row][col][state]){
                continue;
            }
            if(row == n-1 && col == m-1){
                ans = time;
                return;
            }
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nc<0 || nr>=n || nr<0 || nc>=m){
                    continue;
                }
                int cost = (state == 0)? 1 : 2;
                int newState = 1-state;
                int nextTime = max(time, moveTime[nr][nc]) + cost;
                if(nextTime < dist[nr][nc][newState]){
                    dist[nr][nc][newState] = nextTime;
                    pq.push({nextTime, nr, nc, newState});
                }
            }

        }
    }
    int minTimeToReach(vector<vector<int>>& moveTime){
        n = moveTime.size();
        m = moveTime[0].size();
        ans = INT_MAX;
        solve(moveTime);
        return ans;
    }
};