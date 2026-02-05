class TrieNode{
    public:
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end=false;
        for (auto& child : children) child = nullptr;
    }

};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    ~Trie(){
        delete root;
    }

    void insert(string word){
        TrieNode* curr = root;
        for (char c: word){
            int val=c-'a';
            if (curr->children[val]==nullptr){
                curr->children[val] = new TrieNode();
            }
            curr = curr->children[val];
        }
        curr->end = true;
    }
    bool search(string word){
        TrieNode* curr = root;
        for (char c: word){
            int val = c-'a';
            if (curr->children[val]==nullptr) return false;
            curr = curr->children[val];
        }
        return curr->end;
    }

    bool startswith(string word){
        TrieNode* curr = root;
        for (char c: word){
            int val = c-'a';
            if (curr->children[val]==nullptr) return false;
            curr = curr->children[val];
        }
        return true;
    }

    void del(string word){
        TrieNode* curr = root;
        for (char c: word){
            int val = c-'a';
            if (curr->children[val] == nullptr) return;
            curr = curr->children[val];
        }
        curr->end = false;
    }
};

class Solution {
public:
    int m,n;
    vector<string> ans;
    Trie trie;

    void solve(int i, int j, string& s, vector<vector<char>>& board){
        if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='.') return;

        char curr = board[i][j];
        s.push_back(curr);

        if (!trie.startswith(s)) {
            s.pop_back();
            return;
        }

        if (trie.search(s)){
            ans.push_back(s);
            trie.del(s);
        }

        board[i][j] = '.';

        solve(i+1, j, s, board);
        solve(i-1, j, s, board);
        solve(i, j+1, s, board);
        solve(i, j-1, s, board);
        s.pop_back();
        board[i][j] = curr;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        for (string word: words){
            trie.insert(word);
        }
        string s="";
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                solve(i, j, s, board);
            }
        }
        return ans;
    }
};