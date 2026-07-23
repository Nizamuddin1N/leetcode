class Solution {
public:
    // vector<vector<int>> allSubsets;
    // vector<int> subset;

    // void solve(int index, vector<int>& nums) {
    //     if (index == nums.size()) {
    //         allSubsets.push_back(subset);
    //         return;
    //     }
    //     subset.push_back(nums[index]);
    //     solve(index + 1, nums);
    //     subset.pop_back();
    //     solve(index + 1, nums);
    // }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_up(n, 1);
        vector<int> dp_down(n, 1);

        int max_length = 1;

        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]< nums[i]){
                    dp_up[i] = max(dp_up[i], dp_down[j] + 1);
                }
                else if(nums[j] > nums[i]){
                    dp_down[i] = max(dp_down[i], dp_up[j] + 1);
                }
            }
            max_length = max({max_length, dp_up[i], dp_down[i]});
        }
        return max_length;
        // int n = nums.size();
        // bool same = true;
        // for(int i=1; i<n; i++){
        //     if(nums[0] != nums[i]){
        //         same = false;
        //         break;
        //     }
        // }
        // if(same){
        //     return 1;
        // }
        // solve(0, nums);

        // int best = 0;

        // for (int i = 0; i < allSubsets.size(); i++) {

        //     if (allSubsets[i].size() <= 2) {
        //         best = max(best, (int)allSubsets[i].size());
        //         continue;
        //     }

        //     bool isWiggle = true;

        //     int prev = allSubsets[i][1] - allSubsets[i][0];

        //     if (prev == 0)
        //         isWiggle = false;

        //     for (int j = 2; j < allSubsets[i].size() && isWiggle; j++) {

        //         int curr = allSubsets[i][j] - allSubsets[i][j - 1];

        //         if (curr == 0 || curr * prev >= 0) {
        //             isWiggle = false;
        //             break;
        //         }

        //         prev = curr;
        //     }

        //     if (isWiggle) {
        //         best = max(best, (int)allSubsets[i].size());
        //     }
        // }

        // return best;
    }
};