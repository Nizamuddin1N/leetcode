class Solution {
public:
    bool canAliceWin(int n) {
        int maxMove = 10;
        while(n>=0){
            if(maxMove>n){
                if((maxMove+1)%2==0){
                    return true;
                }
                else{
                    return false;
                }
            }
            n -= maxMove;
            maxMove--;
        }
        return true;
    }
};