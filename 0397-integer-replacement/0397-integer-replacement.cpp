class Solution {
public:
    int integerReplacement(int n) {
        int steps = 0;
        long num = n;
        while(num != 1){
            if((num & 1) == 0){
                num >>= 1;
            }
            else{
                if(num != 3 && (num & 3) == 3){
                    num++;
                }
                else{
                    num--;
                }
            }
            steps++;
        }
        return steps;
    }
};