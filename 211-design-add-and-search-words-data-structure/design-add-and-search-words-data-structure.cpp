class TrieNode{
    public:
    bool end;
    TrieNode* children[26];

    TrieNode(){
        end=false;
        for (auto& c: children) c = nullptr;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();

    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c: word){
            int idx = c-'a';
            if (curr->children[idx]==nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
    }

    bool dfs(TrieNode* curr, string word, int index){
        if (index==word.size()){
            return curr->end;
        }

        if (word[index]!='.'){
            if (!curr->children[word[index]-'a']) return false;
            return dfs(curr->children[word[index]-'a'], word, index+1);
        }

        else{
            for (auto node: curr->children){
                if(!node) continue;
                if (dfs(node, word, index+1)) return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return dfs(curr, word, 0);
  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */