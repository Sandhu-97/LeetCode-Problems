class Solution {
public:


    bool isSafe(int row, int col, int n, vector<string>& curr, unordered_set<int>& vertical, unordered_set<int>& diagonal, unordered_set<int>& anti_diagonal){
        if (row>=n || row<0 || col<0 || col>=n) return false;
        
        if (vertical.count(col)) return false;
        if (diagonal.count(row-col)) return false;
        if (anti_diagonal.count(row+col)) return false;
        return true;
        // for (int r=row-1;r>=0;r--){
        //     if (curr[r][col]=='Q') return false;
        // }
        
        // for (int r=row-1, c=col-1;r>=0 && c>=0;r--, c--){
        //     if (curr[r][c]=='Q') return false;
        // }
        // for (int r=row-1, c=col+1;r>=0 && c<n; r--, c++){
        //     if (curr[r][c]=='Q') return false;
        // }
        // return true;
    }

    void solve(int row, int n, vector<string>& curr, vector<vector<string>>& res, unordered_set<int>& vertical, unordered_set<int>& diagonal, unordered_set<int>& anti_diagonal){
        if (row>=n){
            res.push_back(curr);
            return;
        }

        for (int col=0; col<n;col++){
            if (isSafe(row, col, n, curr, vertical, diagonal, anti_diagonal)){
                curr[row][col]='Q';
                vertical.insert(col);
                diagonal.insert(row-col);
                anti_diagonal.insert(col+row);
                solve(row+1, n, curr, res, vertical, diagonal, anti_diagonal);
                curr[row][col] = '.';
                vertical.erase(col);
                diagonal.erase(row-col);
                anti_diagonal.erase(row+col);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        unordered_set<int> vertical;
        unordered_set<int> diagonal;
        unordered_set<int> anti_diagonal;
        solve(0, n, curr, res, vertical, diagonal, anti_diagonal);
        return res;
    }
};