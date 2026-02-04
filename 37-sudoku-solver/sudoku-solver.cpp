class Solution {
public:
    bool valid(int row, int col, char dig, vector<vector<char>>& board){
        for (int i=0;i<9;i++){
            if (board[row][i]==dig) return false;
            if (board[i][col]==dig) return false;
        }

        row = (row/3)*3;
        col = (col/3)*3;

        for (int i=row;i<row+3;i++){
            for (int j=col;j<col+3;j++){
                if (board[i][j]==dig) return false;
            }
        }
        return true;
    }

    bool solve(int row, int col, vector<vector<char>>& board){
        if (row==9) return true;
        int nextrow = row, nextcol = col+1;
        if (col==9) {
            nextrow=row+1;
            nextcol=0;
        }

        if (board[row][col]!='.') return solve(nextrow, nextcol, board);

        for (char dig='1' ; dig<='9' ; dig++){
            if (valid(row, col, dig, board)){
                board[row][col]  = dig;
                if (solve(nextrow, nextcol, board)) return true;
                board[row][col] = '.';
            }
        }

        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};