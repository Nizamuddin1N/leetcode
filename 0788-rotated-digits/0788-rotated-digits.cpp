class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=0; i<=n; i++){
            int number = i;
            bool changed = false;
            bool valid = true;
            while(number != 0){
                int m = number %10;
                number /= 10;
                if(m== 3 || m == 4 || m==7){
                    valid = false;
                    break;
                }
                else if(m== 5 || m == 2 || m == 6 || m == 9){
                    changed = true;
                }

            }
            if(valid && changed){
                ans++;
            }
        }
        return ans;
    }
};