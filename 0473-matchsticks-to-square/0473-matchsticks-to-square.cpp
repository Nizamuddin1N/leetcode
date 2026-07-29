class Solution {
public:
    vector<bool> presentmatchsticks;
    int target;
    bool recursive(int side, int index, int sum, vector<int>& matchsticks){
        if(side == 3){
            return true;
        }
        if(sum == 0){
            return recursive(side+1, 0, target, matchsticks);
        }

        for(int i= index; i<matchsticks.size(); i++){
            if(presentmatchsticks[i]){
                continue;
            }
            if(matchsticks[i] > sum){
                continue;
            }
            presentmatchsticks[i] = true;
            if (recursive(side, i + 1, sum - matchsticks[i], matchsticks))
                return true;
            presentmatchsticks[i] = false;

        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int perimeter = 0;

        for (int x : matchsticks)
            perimeter += x;

        if (perimeter % 4 != 0)
            return false;

        target = perimeter / 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        presentmatchsticks.assign(matchsticks.size(), false);

        return recursive(0, 0, target, matchsticks);
    }
};