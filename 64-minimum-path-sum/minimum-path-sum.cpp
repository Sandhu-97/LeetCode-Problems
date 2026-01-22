class Solution {
public:
    vector<vector<int>> dp;
    int m,n;

    int solve(int i, int j, vector<vector<int>>& grid){
        if (i>=m || j>=n) return INT_MAX;
        if (i==m-1 && j == n-1) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i+1, j, grid), solve(i, j+1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));
        return solve(0,0,grid);
    }
};