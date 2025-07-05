class Solution {
public:


    bool isSafe(int row, int col, int n, vector<string>& curr){
        if (row>=n || row<0 || col<0 || col>=n) return false;

        for (int r=row;r>=0;r--){
            if (curr[r][col]=='Q') return false;
        }

        for (int r=row, c=col;r>=0 && c>=0;r--, c--){
            if (curr[r][c]=='Q') return false;
        }
        for (int r=row, c=col;r>=0 && c<n; r--, c++){
            if (curr[r][c]=='Q') return false;
        }
        return true;
    }

    void solve(int row, int n, vector<string>& curr, vector<vector<string>>& res){
        if (row>=n){
            res.push_back(curr);
            return;
        }

        for (int col=0; col<n;col++){
            if (isSafe(row, col, n, curr)){
                curr[row][col]='Q';
                solve(row+1, n, curr, res);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        solve(0, n, curr, res);
        return res;
    }
};