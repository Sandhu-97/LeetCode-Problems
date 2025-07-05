class Solution {
public:


    bool isSafe(int row, int col, int n, vector<string>& curr, vector<bool>& vertical, vector<bool>& diagonal, vector<bool>& anti_diagonal){
        if (row>=n || row<0 || col<0 || col>=n) return false;
        
        if (vertical[col]) return false;
        if (diagonal[row-col+(n-1)]) return false;
        if (anti_diagonal[row+col]) return false;
        return true;
    }

    void solve(int row, int n, vector<string>& curr, vector<vector<string>>& res, vector<bool>& vertical, vector<bool>& diagonal, vector<bool>& anti_diagonal){
        if (row>=n){
            res.push_back(curr);
            return;
        }

        for (int col=0; col<n;col++){
            if (isSafe(row, col, n, curr, vertical, diagonal, anti_diagonal)){
                curr[row][col]='Q';
                vertical[col] = true;
                diagonal[row-col+(n-1)]=true;
                anti_diagonal[row+col]=true;
                solve(row+1, n, curr, res, vertical, diagonal, anti_diagonal);
                curr[row][col] = '.';
                vertical[col] = false;
                diagonal[row-col+(n-1)]=false;
                anti_diagonal[row+col]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        vector<bool> vertical(n, false);
        vector<bool> diagonal(2*n-1, false);
        vector<bool> anti_diagonal(2*n-1, false);
        solve(0, n, curr, res, vertical, diagonal, anti_diagonal);
        return res;
    }
};