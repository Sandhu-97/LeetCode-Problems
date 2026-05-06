class TrieNode{
    public:
    vector<TrieNode*> children;
    bool end;
    string word;
    TrieNode(){
        children.assign(26, nullptr);
        end=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* curr=root;
        for (char c: word){
            int idx=c-'a';
            if (!curr->children[idx]){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->end=true;
        curr->word=word;
    }
};

class Solution {
public:
    int m,n;
    vector<string> ans;
    Trie trie;
    void solve(int i, int j, TrieNode* curr, vector<vector<char>>& board){
        if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='.') return;
        char temp=board[i][j];
        int idx=temp-'a';
        if (!curr->children[idx]) return;

        curr=curr->children[idx];

        if (curr->end) {
            ans.push_back(curr->word);
            curr->end=false;
        }

        board[i][j]='.';
        solve(i+1, j, curr, board);
        solve(i-1, j, curr, board);
        solve(i, j+1, curr, board);
        solve(i, j-1, curr, board);
        board[i][j]=temp;




    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();

        for (string word: words){
            trie.insert(word);
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                solve(i, j, trie.root, board);
            }
        }

        return ans;


    }
};