class Solution {
public:
    vector<int> ans;
    void dfs(int num, int n){
        if(num>n){
            return;
        }
        ans.push_back(num);
        for(int i=0; i<=9; i++){
            int next = num*10+i;
            if(next > n){
                break;
            }
            dfs(next, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<=9; i++){
            if(i>n){
                break;
            }
            dfs(i, n);
        }
        return ans;
    }
};