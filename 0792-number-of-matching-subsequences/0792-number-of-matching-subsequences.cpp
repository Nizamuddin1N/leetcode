class Solution {
public:
    // string subsequence="";
    // set<string>st;
    // void recursive(string &s, vector<string>& words, int index){
    //     if(index==s.size()){
    //         st.insert(subsequence);
    //         return;
    //     }
    //     subsequence.push_back(s[index]);
    //     recursive(s, words, index+1);
    //     subsequence.pop_back();
    //     recursive(s, words, index+1);
    // }
    int numMatchingSubseq(string s, vector<string>& words) {
        // recursive(s, words, 0);
        // for(auto &x:words){
        //     if(st.count(x)){
        //         ans++;
        //     }
        // }
        // return ans;
        // for(auto &word : words){
        //     int i=0;
        //     int j=0;
        //     while(i<s.size() && j<word.size()){
        //         if(s[i]==word[j]){
        //             j++;
        //         }
        //         i++;
        //     }
        //     if(j== word.size()){
        //         ans++;
        //     }
        // }
        // return ans;
        int ans = 0;
        unordered_map<char, vector<int>>pos;
        for(int i=0; i<s.size(); i++){
            pos[s[i]].push_back(i);
        }
        for(string &word:words){
            int prevIndex = -1;
            bool found = true;

            for(char ch:word){
                if(pos.find(ch) == pos.end()){
                    found = false;
                    break;
                }
                auto it = upper_bound(pos[ch].begin(), pos[ch].end(), prevIndex);
                if(it == pos[ch].end()){
                    found = false;
                    break;
                }
                prevIndex = *it;
            }
            if(found){
                ans++;
            }
        }
        return ans;
    }
};