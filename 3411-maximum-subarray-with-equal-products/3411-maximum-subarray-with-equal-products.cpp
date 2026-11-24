class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    int maxLength(vector<int>& nums) {
        int ans = 1;
        for(int j=0; j<nums.size(); j++){
          int b=0;
          long long product = 1;
          int lcmNumber = 1;
          for(int i=j; i<nums.size(); i++){
            if (product > 25200 / nums[i]) break;
            product *= nums[i];
            int a = nums[i];
            int gcdNumber = gcd(a, b);
            lcmNumber = (lcmNumber / gcd(lcmNumber, nums[i])) * nums[i];
            if(gcdNumber*lcmNumber == product){
                ans = max(ans, i - j + 1);
            }
            b = gcdNumber;
          }

        }
        return ans == 1?0:ans;

    }
};