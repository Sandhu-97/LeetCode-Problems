class Solution {
public:

    int n;
    vector<string> curr;
    int count;
    bool valid (int row, int col){
        if (row<0 || row>=n || col<0 || col>=n ) return false;
        for (int i=row-1 ; i>=0 ; i--) if (curr[i][col]=='Q') return false;
        for (int i=row-1, j=col-1 ; i>=0 && j>=0 ; i--, j--) if (curr[i][j]=='Q') return false;
        for (int i=row-1, j=col+1 ; i>=0 && j<n ; i--, j++) if (curr[i][j]=='Q') return false;
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
                solve(row+1);
                curr[row][col] = '.';
            }
        }
    }
    int totalNQueens(int N) {
        n=N;
        curr.assign(n, string(n, '.'));
        count=0;
        solve(0);
        return count;
    }
};