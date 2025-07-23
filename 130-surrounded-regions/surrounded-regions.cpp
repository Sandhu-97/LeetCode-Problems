class Solution {
public:

    int rows, cols;
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if (row<0 || col<0 || row>=rows || col>=cols || board[row][col]=='X' || visited[row][col]) return;

        visited[row][col] = true;

        dfs(row+1, col, board, visited);
        dfs(row-1, col, board, visited);
        dfs(row, col+1, board, visited);
        dfs(row, col-1, board, visited);
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i=0;i<rows;i++){
            if (board[i][0]=='O' && !visited[i][0]){
                dfs(i, 0, board, visited);
            }
            if (board[i][cols-1]=='O' && !visited[i][cols-1]){
                dfs(i, cols-1, board, visited);
            }
        }

        for (int i=0;i<cols;i++){
            if (board[0][i]=='O' && !visited[0][i]){
                dfs(0,i, board, visited);
            }
            if (board[rows-1][i]=='O' && !visited[rows-1][i]){
                dfs(rows-1, i, board, visited);
            }
        }

        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (!visited[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }

    }
};