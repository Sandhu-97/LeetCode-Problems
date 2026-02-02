class Solution {
public:
    int m, n;

    void solve(int row, int col, vector<vector<char>>& grid){
        if (row<0 || col<0 || row>=m || col>=n) return;
        if (grid[row][col]=='0') return;

        grid[row][col]='0';
        solve(row+1, col, grid);
        solve(row-1, col, grid);
        solve(row, col+1, grid);
        solve(row, col-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1') {
                    solve(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};