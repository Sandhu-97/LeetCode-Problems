class Solution {
public:
    vector<vector<int>> grid, dp;
    int m,n;
    int solve (int i, int j){
        if (i>=m || j>=n || grid[i][j]==1) return 0;
        if (i==m-1 && j==n-1) return 1;
        if (dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = solve(i+1, j) + solve(i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        m=grid.size();
        n=grid[0].size();
        dp.assign(m, vector<int>(n, -1));
        return solve(0,0);
    }
};