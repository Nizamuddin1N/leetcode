class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(auto &x:direction){
                int ic = i+x.first;
                int jc = j+x.second;
                if(ic>=0 && jc >=0 && ic<m && jc<n && !visited[ic][jc]){
                    visited[ic][jc] = true;
                    mat[ic][jc] = mat[i][j]+1;
                    q.push({ic, jc});
                }
            }
        }
        return mat;
    }
};