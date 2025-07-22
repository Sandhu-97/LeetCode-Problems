class Solution {
public:

    int m, n;

    void solve(int i, int j, vector<vector<char>>& grid){
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1' ) return;

        grid[i][j] = '0';
        solve(i+1, j, grid);
        solve(i-1, j, grid);
        solve(i, j+1, grid);
        solve(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1' ){
                    solve(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};