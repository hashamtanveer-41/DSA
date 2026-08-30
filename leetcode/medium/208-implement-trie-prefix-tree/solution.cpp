class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for (int i=0; i< 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    
public:

    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        // index
        int index = word[0] -'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            // Present
            child = root->children[index];
        }else{
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        return insertUtil(root, word);
    }
    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        // index
        int index = word[0] -'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            // Present
            child = root->children[index];
        }else{
            // Absent
           return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
    bool prefixUtil (TrieNode* root, string word){
        if(word.length()==0){
            return true;
        }
        // index
        int index = word[0] -'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            // Present
            child = root->children[index];
        }else{
            // Absent
           return false;
        }
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

