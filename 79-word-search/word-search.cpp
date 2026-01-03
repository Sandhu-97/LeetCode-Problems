class Solution {
public:

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    bool solve(int i, int j, int idx, int&m ,int& n, vector<vector<char>>& board, string& word){
        if (idx>=word.size()) return true;
        if (i>=m || i<0 || j<0 || j>=n || word[idx]!=board[i][j]) return false;

        bool ans = false;
        char temp = board[i][j];
        board[i][j] = '.';
        for (int k=0;k<4;k++){
            if (solve(i+dx[k], j+dy[k], idx+1, m, n, board, word)){
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j] == word[0] && solve(i,j,0,m,n,board,word)) return true;
            }
        }
        return false;
    }
};