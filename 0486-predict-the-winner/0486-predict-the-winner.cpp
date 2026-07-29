class Solution {
public:
    bool recursive(int start, int end, int sum1, int sum2, bool turn, vector<int>& nums){
        if(start>end){
            return sum1 >= sum2;
        }
        if(turn){
            return recursive(start+1, end, sum1+nums[start], sum2, false, nums) || recursive(start, end-1, sum1+nums[end], sum2, false, nums);
        }
        else{
            return recursive(start+1, end, sum1, sum2+nums[start], true, nums) && recursive(start, end-1, sum1, sum2 + nums[end], true, nums);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return recursive(0, nums.size()-1, 0, 0, true, nums);
    }
};