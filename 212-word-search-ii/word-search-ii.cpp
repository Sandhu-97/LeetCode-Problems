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
};

class Solution {
public:
    int m,n;
    vector<string> ans;
    Trie trie;
    string s;

    void solve(int i, int j, TrieNode* node , vector<vector<char>>& board){
        if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='.') return;

        char curr = board[i][j];
        int val = curr-'a';

        if (!node->children[val]) return;
        node = node->children[val];
        s.push_back(curr);

        if (node->end){
            ans.push_back(s);
            node->end = false;
        }

        board[i][j] = '.';

        solve(i+1, j, node, board);
        solve(i-1, j, node, board);
        solve(i, j+1, node, board);
        solve(i, j-1, node, board);
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
                solve(i, j, trie.root, board);
            }
        }
        return ans;
    }
};