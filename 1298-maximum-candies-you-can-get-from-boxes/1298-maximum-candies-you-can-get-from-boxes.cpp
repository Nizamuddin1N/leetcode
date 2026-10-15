class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q1; //track boxes which are open.
        queue<int>q2; //track boxes which i have.
        int n = candies.size();
        vector<bool>visited(n, false);
        for(int x : initialBoxes){
            if(status[x] == 1){
                q1.push(x);
            }
            else{
                q2.push(x);
            }
        }
        int ans=0;
        while(!q1.empty()){
            int box = q1.front();
            q1.pop();
            if(visited[box]) continue;
            visited[box] = true;
            ans += candies[box];
            for(int x:containedBoxes[box]){
                if(status[x] == 0){
                    q2.push(x);
                }
                else{
                    q1.push(x);
                }
            }
            for(int x:keys[box]){
                status[x] = 1;
            }
            queue<int>temp;
            while(!q2.empty()){
                int node = q2.front();
                if(visited[node]) continue;
                q2.pop();
                if(status[node] == 1){
                    q1.push(node);
                }
                else{
                    temp.push(node);
                }
            }
            q2 = temp;
        }
        return ans;
    }
};