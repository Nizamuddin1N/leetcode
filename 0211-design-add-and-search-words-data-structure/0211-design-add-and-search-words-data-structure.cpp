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
        isTerminal= false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    void insert(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
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
    void addWord(string word) {
        insert(root, word);
    }
    
    bool searchWord(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        if(word[0] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->children[i] != NULL) {
                    if(searchWord(root->children[i], word.substr(1))) {
                        return true;
                    }
                }
            }
            return false;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchWord(child, word.substr(1));
    }
    bool search(string word) {
       return searchWord(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */