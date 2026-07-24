class Solution {
public:
    string subsequence;

    bool solve(int index, string &t, string &s){
        if (subsequence == s){
            return true;
        }
        else if(index == t.length()){
            return false;
        }
        subsequence.push_back(t[index]);
        bool ans1 = solve(index + 1, t, s);
        subsequence.pop_back();
        bool ans2 = solve(index + 1, t, s);
        return ans1 || ans2;
    }

    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;
        if (t.empty())
            return false;


        // return solve(0, t, s);
        int sizeofString = t.length();
        int j=0;
        for(int i=0; i<sizeofString; i++){
            if(t[i] == s[j]){
                j++;
            }
        }
        if(j== s.length()){
            return true;
        }
        return false;
    }
};