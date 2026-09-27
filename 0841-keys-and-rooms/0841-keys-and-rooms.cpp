class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int noofroom = rooms.size();
        vector<bool>visited(noofroom, false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int key : rooms[node]){
                if(!visited[key]){
                    visited[key]=true;
                    q.push(key);
                }
            }
        }
        for(int i=0; i<noofroom; i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;

    }
};