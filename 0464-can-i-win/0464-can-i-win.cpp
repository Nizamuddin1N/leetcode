class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(1+maxChoosableInteger)/2 < desiredTotal){
            return false;
        }
        unordered_map<int, bool>memo;
        function<bool(int, int)>dfs = [&](int mask, int sum)->bool{
            if(memo.find(mask) != memo.end()){
                return memo[mask];
            }

            for(int i=0; i<maxChoosableInteger; i++){
                if(((mask >> i) & 1) == 0){
                    int choosenNumber = i +1;

                    if((choosenNumber + sum >= desiredTotal) || !dfs(mask | (1 << i), choosenNumber + sum)){
                        memo[mask] = true;
                        return true;
                    }
                }
            }
            memo[mask] = false;
            return false;
        };
        return dfs(0, 0);
    }
};