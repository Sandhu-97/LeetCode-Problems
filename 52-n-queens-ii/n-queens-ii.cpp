class Solution {
public:

    int n;
    vector<string> curr;
    int count;
    vector<bool> cols;
    vector<bool> diagonals;
    vector<bool> antidiagonals;

    bool valid (int row, int col){
        if (row<0 || row>=n || col<0 || col>=n ) return false;
        if (cols[col] || diagonals[n-1+row-col] || antidiagonals[row+col]) return false;
        return true;
    }


    void solve(int row){
        if (row>=n){
            count++;
            return;
        }
        for (int col=0;col<n;col++){
            if (valid(row, col)){
                curr[row][col] = 'Q';
                cols[col] = true;
                diagonals[n-1+row-col] = true;
                antidiagonals[row+col] = true;;
                solve(row+1);
                curr[row][col] = '.';
                cols[col] = false;;
                diagonals[n-1+row-col] = false;
                antidiagonals[row+col] = false;
            }
        }
    }
    int totalNQueens(int N) {
        n=N;
        curr.assign(n, string(n, '.'));
        count=0;
        cols.assign(n, false);
        diagonals.assign(2*n-1, false);
        antidiagonals.assign(2*n-1, false);
        solve(0);
        return count;
    }
};