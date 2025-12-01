class Solution {
public:


    bool isSafe(int row, int col, int n, vector<string>& curr){
        if(row>= n || row<0 || col < 0 || col>=n) return false;
        for (int i=row-1;i>=0;i--){
            if (curr[i][col] == 'Q') return false;
        }

        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if (curr[i][j]=='Q') return false;
        } 
        for (int i=row-1, j=col+1;i>=0 && j<n; i--, j++) if (curr[i][j]=='Q') return false;

        return true;
    }
    void solve(int i, int n, vector<string>& curr, vector<vector<string>>& ans){
        if (i>=n){
            ans.push_back(curr);
            return;
        }
        for (int j=0;j<n;j++){
            if (isSafe(i, j, n, curr)){
                curr[i][j] = 'Q';
                solve(i+1, n, curr, ans);
                curr[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        solve(0, n, curr, ans);
        return ans;
    }
};