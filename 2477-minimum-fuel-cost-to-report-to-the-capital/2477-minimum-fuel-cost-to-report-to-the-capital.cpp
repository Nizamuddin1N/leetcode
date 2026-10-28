class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        if(roads.empty()){
            return 1ll*0;
        }
        long long ans = 0;
        vector<vector<int>>graph(n);
        // vector<bool>visited(n, false);
        for(auto&road:roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        vector<int>degree(n);
        queue<int>q;
        for(int i=0; i<n; i++){
            degree[i] = graph[i].size();
            if(degree[i] == 1){
                q.push(i);
            }
        }
        vector<int>people(n, 1);
        while(!q.empty()){
            int city = q.front();
            q.pop();
            if(city == 0){
                continue;
            }
            for(int neigh:graph[city]){
                if(degree[neigh] == 0){
                    continue;
                }
                ans += (people[city] + seats - 1)/seats;
                people[neigh] += people[city];
                degree[city] = 0;
                degree[neigh]--;
                if(degree[neigh] == 1 && neigh != 0){
                    q.push(neigh);
                }
                break;
            }
        }
        return ans;



        
    //     while(!q.empty()){
    //         int sz = q.size();
    //         if(un == q.size()){
    //             break;
    //         }
    //         for(int i=0; i<sz; i++){
    //             auto [city, people] = q.front();
    //             for(int neigh:graph[city]){
    //                 if(people +1 > seats){
    //                     ans++;
    //                     continue;
    //                 }
    //                 if(!visited[neigh]){
    //                     visited[neigh] = true;
    //                     ans++;
    //                     if(neigh == 0){
    //                         q.pop();
    //                         continue;
    //                     }
    //                     else if(people +1 <= seats){
    //                         q.pop();
    //                         q.push({neigh, people+1});
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    }
};