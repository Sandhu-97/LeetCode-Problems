class Solution {
public:
    bool solve(int i, int j, int idx, int n, int m, vector<vector<char>>& board, string& word){
        if (idx==word.size()) return true;
        if (i>=n || i<0 || j>=m || j<0) return false;
        if (board[i][j]!=word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '.';
        bool left = solve(i, j-1, idx+1, n, m, board, word);
        bool right = solve(i, j+1, idx+1, n, m, board, word);
        bool up = solve(i-1, j, idx+1, n, m, board, word);
        bool down = solve(i+1, j, idx+1, n, m, board, word);

        board[i][j] = temp;
        return left || right || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (solve(i, j, 0, n, m, board, word)) return true;
            }
        }
        return false;
    }
};