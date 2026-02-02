class Solution {
public:
    int m,n;
    int solve(int row, int col, vector<vector<int>>& grid){
        if (row<0 || row>=m || col<0 || col>=n || grid[row][col]<=0 ) return 0;

        int curr = grid[row][col];
        grid[row][col] = -grid[row][col];

        int up = solve(row-1, col, grid);
        int down = solve(row+1, col, grid);
        int left = solve(row, col-1, grid);
        int right = solve(row, col+1, grid);

        grid[row][col ] = curr;
        return curr + max(up, max(down, max(left, right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]>0){
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }
        return ans;
    }
};