class Solution {
public:
    map<vector<int>, int>dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp.count(needs)){
           return dp[needs];
        }
        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }

        int rowSpecial = special.size();

        for (int i = 0; i < rowSpecial; i++) {

            bool flag = true;
            vector<int> remaining = needs;
            for (int j = 0; j < needs.size(); j++) {

                if (special[i][j] > needs[j]) {
                    flag = false;
                    break;
                }

                remaining[j] -= special[i][j];
            }

            if (flag) {
                ans = min(ans, special[i][needs.size()] + shoppingOffers(price, special, remaining));
            }
        }

        return dp[needs] = ans;
    }
};