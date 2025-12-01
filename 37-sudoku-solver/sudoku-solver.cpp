class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for (int i=0;i<9;i++){
            if (board[row][i]==dig) return false;
            if (board[i][col]==dig) return false;
        }    
        int newrow = (row/3) * 3, newcol = (col/3)*3;

        for (int i=newrow;i<newrow+3;i++){
            for (int j=newcol;j<newcol+3;j++){
                if (board[i][j]==dig) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){
        if (row==9) return true; 
        int nextrow = row, nextcol = col+1;
        if (nextcol==9) {
            nextrow=row+1;
            nextcol=0;
        }

        if(board[row][col]!='.') return solve(board, nextrow, nextcol);
        for (char dig = '1'; dig<='9'; dig++){

            if (isSafe(board, row, col, dig)){
                board[row][col] = dig;
                if (solve(board, nextrow, nextcol)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};