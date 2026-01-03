class Solution {
public:

    bool valid(int row, int col, int n, vector<string>& curr){
        if (row>=n || row<0 || col>=n || col<0) return false;
        for (int i=row-1;i>=0;i--) if (curr[i][col]=='Q') return false;
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) if (curr[i][j]=='Q') return false;
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) if (curr[i][j]=='Q') return false;
        return true;
    }

    void solve(int row, int n, vector<string>& curr, vector<vector<string>>& ans){
        if (row>=n){
            ans.push_back(curr);
            return;
        }

        for (int col=0;col<n;col++){
            if (valid(row, col, n, curr)){
                curr[row][col] = 'Q';
                solve(row+1, n, curr, ans);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, curr, ans);
        return ans;
    }
};