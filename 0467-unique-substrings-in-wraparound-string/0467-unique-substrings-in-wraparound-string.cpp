class Solution {
public:
    int ans = 0;
    string result;
    set<string> st;

    void recursive(int index, string &s) {

        if (index == s.length()) {

            if (!result.empty()) {

                if (result.size() == 1) {

                    if (st.insert(result).second) {
                        ans++;
                    }

                } else {

                    bool valid = true;

                    for (int i = 1; i < result.size(); i++) {

                        if (result[i - 1] == 'z' && result[i] == 'a')
                            continue;

                        if (result[i] - result[i - 1] != 1) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid && st.insert(result).second) {
                        ans++;
                    }
                }
            }

            return;
        }

        // Include
        result.push_back(s[index]);
        recursive(index + 1, s);

        // Backtrack
        result.pop_back();

        // Exclude
        recursive(index + 1, s);
    }

    int findSubstringInWraproundString(string s) {
        vector<int> longest(26, 0);
        int n = s.size();
        longest[s[0] - 'a'] = 1;
        int currentLength = 1;
        for(int i=1; i<n; i++){
            if((s[i]-s[i-1] == 1) || (s[i] == 'a' && s[i-1] == 'z')){
                currentLength++;
            }
            else{
                currentLength = 1;
            }
            longest[s[i]-'a'] = max(longest[s[i]-'a'], currentLength);
        }
        int sum=0;
        for(auto x:longest){
            sum+=x;
        }

        return sum;
        // set<string>st;
        // int ans = 0;
        // int sizeofstring = s.size();
        // for(int i=0; i<sizeofstring; i++){
        //     string temp = "";
        //     temp.push_back(s[i]);
        //     if(st.insert(temp).second){
        //         ans++;
        //     }
        //     for(int j=i+1; j<sizeofstring; j++){
        //         if((s[j] == 'a' && s[j-1]=='z') || (s[j] - s[j-1] == 1)){
        //             temp.push_back(s[j]);
        //             if(st.insert(temp).second){
        //                 ans++;
        //             }
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     // for(int j=i; j<sizeofstring; j++){
        //     //     temp.push_back(s[j]);
        //     //     bool valid = true;
        //     //     for(int k=1; k<temp.size(); k++){
        //     //         if(temp[k] == 'a' && temp[k-1] == 'z'){
        //     //             continue;
        //     //         }
        //     //         else if(temp[k] - temp[k-1] != 1){
        //     //             valid = false;
        //     //             break;
        //     //         }
        //     //     }
        //     //     if(valid && st.insert(temp).second){
        //     //         ans++;
        //     //     }
        //     // }
        // }
        // return ans;
        // // recursive(0, s);
        // // return ans;
    }
};