class Solution {
public:
    string recursion(string &s, int &k){
        if(s.length()<=k){
            return s;
        }
        int part=0;
        string final = "";
        for(int i=0; i<s.length(); i++){
            part += s[i]-'0';
            if((i+1) % k == 0){
                final += to_string(part);
                part=0;
            }
        }
        if(s.length()%k != 0){
            final += to_string(part);
        }
        return recursion(final, k);
    }
    string digitSum(string s, int k) {
        return recursion(s, k);
    }
};