class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxScore = 0;
        int availableLetters[26] = {0}; //count frequency in letters
        for(char &letter: letters){
            availableLetters[letter - 'a']++;
        }
        int wordSize = words.size();
        //iterate through bit masking
        for(int mask=0; mask < (1<<wordSize); ++mask){
            int letterNeeded[26] = {0};
            for(int wordIdx = 0; wordIdx<wordSize; ++wordIdx){
                if((mask>>wordIdx) & 1){
                    for(char &letter:words[wordIdx]){
                        letterNeeded[letter-'a'] ++;
                    }
                }
            }
            bool isValidSubset = true;
            int currentScore = 0;
            for(int letterIdx = 0; letterIdx<26; ++letterIdx){
                if(letterNeeded[letterIdx]>availableLetters[letterIdx]){
                    isValidSubset = false;
                    break;
                }
                currentScore +=letterNeeded[letterIdx]*score[letterIdx];
            }
            if(isValidSubset && currentScore>maxScore){
                maxScore = currentScore;
            }
        }
        return maxScore;
    }
};