class TrieNode{
    public:
    bool end;
    TrieNode* children[26];

    TrieNode(){
        end=false;
        for (auto& ch: children) ch=nullptr;
    }
};

class Trie{
    public: 
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void add(string word){
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

    bool search(string word, string& ans){
        TrieNode* curr = root;

        for (char c: word){
            int idx = c-'a';
            if (curr->children[idx]==nullptr) break;
            curr=curr->children[idx];
            ans.push_back(c);
            if (curr->end) return true;
        }
        return curr->end;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sen) {
        Trie trie;
        for (string s: dictionary){
            trie.add(s);
        }
        string word;
        string res;

        stringstream ss(sen);

        while (ss >> word){
            string root = "";
            bool find = trie.search(word, root);
            if (find) res += root + ' ';
            else res += word + ' ';
        }
        
        res.pop_back();
        return res;
    }
};