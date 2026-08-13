class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Solution {
public:
    vector<string> result;
    TrieNode* root;
    Solution(){
        root = new TrieNode('\0');
    }

    void insert(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal =true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }
    void construct(int index, string &s, string current){
        if(index==s.length()){
            current.pop_back();
            result.push_back(current);
            return;
        }
        TrieNode* temp = root;
        for(int i=index; i<s.length(); i++){
            int position = s[i] - 'a';
            if(temp->children[position] == NULL){
                break;
            }
            temp = temp->children[position];
            if(temp->isTerminal){
                string word = s.substr(index, i-index+1);
                construct(i+1, s, current+word+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        for(int i=0; i<n; i++){
            insert(root, wordDict[i]);
        }
        construct(0, s, "");
        return result;
    }
};