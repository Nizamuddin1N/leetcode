class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long>prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + tasks[i];
        }
        long long total = prefix[n];
        vector<int> ans;
        long long pos =0;
        for(int t:shifts){
            pos += t;
            if(pos >= total){
                ans.push_back(0);
                pos = 0;
            }
            else{
                int idx = upper_bound(prefix.begin(), prefix.end(), pos) - prefix.begin() -1;
                ans.push_back(n-idx);
            }
        }
        return ans;
    }
};