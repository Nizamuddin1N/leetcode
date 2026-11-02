class Solution {
public:
    int solve(int idx, vector<string>&words, vector<int>&freq, vector<int>&score){
        if(idx == words.size()){
            return 0;
        }
        //choice1: skip the current word
        int skip = solve(idx+1, words, freq, score);
        //choice2: take the current word
        int wordScore = 0;
        bool possible = true;
        for(char ch: words[idx]){
            freq[ch - 'a']--;
            wordScore += score[ch-'a'];
            if(freq[ch-'a']<0){
                possible = false;
            }
        }
        int take = 0;
        if(possible){
            take = wordScore + solve(idx+1, words, freq, score);
        }
        //backtracking
        for(char ch: words[idx]){
            freq[ch-'a']++;
        }
        return max(take, skip);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26);
        for(char& letter:letters){
            freq[letter - 'a']++;
        }
        return solve(0, words, freq, score);
        // int maxScore = 0;
        // int availableLetters[26] = {0}; //count frequency in letters
        // for(char &letter: letters){
        //     availableLetters[letter - 'a']++;
        // }
        // int wordSize = words.size();
        // //iterate through bit masking
        // for(int mask=0; mask < (1<<wordSize); ++mask){
        //     int letterNeeded[26] = {0};
        //     for(int wordIdx = 0; wordIdx<wordSize; ++wordIdx){
        //         if((mask>>wordIdx) & 1){
        //             for(char &letter:words[wordIdx]){
        //                 letterNeeded[letter-'a'] ++;
        //             }
        //         }
        //     }
        //     bool isValidSubset = true;
        //     int currentScore = 0;
        //     for(int letterIdx = 0; letterIdx<26; ++letterIdx){
        //         if(letterNeeded[letterIdx]>availableLetters[letterIdx]){
        //             isValidSubset = false;
        //             break;
        //         }
        //         currentScore +=letterNeeded[letterIdx]*score[letterIdx];
        //     }
        //     if(isValidSubset && currentScore>maxScore){
        //         maxScore = currentScore;
        //     }
        // }
        // return maxScore;
    }
};