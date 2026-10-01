class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<int> component(n);

        int comp = 0;
        component[arr[0].second] = comp;

        for(int i = 1; i < n; i++){
            if(arr[i].first - arr[i - 1].first > maxDiff){
                comp++;
            }

            component[arr[i].second] = comp;
        }

        vector<bool> ans;

        for(auto query : queries){

            int u = query[0];
            int v = query[1];

            if(component[u] == component[v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};