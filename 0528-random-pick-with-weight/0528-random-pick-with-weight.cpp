class Solution {
public:
    vector<int>prefixSum;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int weight : w){
            sum +=weight;
            prefixSum.push_back(sum);
        }
    }
    int pickIndex() {
        int sum = prefixSum.back();
        int randomNumber = rand()%sum + 1;
        int index = lower_bound(prefixSum.begin(), prefixSum.end(), randomNumber) - prefixSum.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */