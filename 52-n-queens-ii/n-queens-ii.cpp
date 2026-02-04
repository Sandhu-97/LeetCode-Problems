class Solution {
public:

    int n;
    vector<string> curr;
    int count;
    unordered_set<int> cols;
    unordered_set<int> diagonals;
    unordered_set<int> antidiagonals;

    bool valid (int row, int col){
        if (row<0 || row>=n || col<0 || col>=n ) return false;
        if (cols.find(col)!=cols.end()) return false;
        if (diagonals.find(row-col) != diagonals.end()) return false;
        if (antidiagonals.find(row+col) != antidiagonals.end()) return false;
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
                cols.insert(col);
                diagonals.insert(row-col);
                antidiagonals.insert(row+col);
                solve(row+1);
                curr[row][col] = '.';
                cols.erase(col);
                diagonals.erase(row-col);
                antidiagonals.erase(row+col);
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