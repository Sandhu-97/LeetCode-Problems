class TrieNode{
    public:
    bool end;
    TrieNode* children[26];

    TrieNode(){
        end=false;
        for (int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (char c: word){
            if (curr->children[c-'a'] == nullptr){
                TrieNode* node = new TrieNode();
                curr->children[c-'a'] = node;
            }
            curr = curr->children[c-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c: word){
            if (curr->children[c-'a']==nullptr) return false;
            curr = curr->children[c-'a'];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix){
            if (curr->children[c-'a'] == nullptr) return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */