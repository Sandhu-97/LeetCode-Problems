class Solution {
public:

    int m, n;

    void solve(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1' || visited[i][j]) return;

        visited[i][j] = true;

        solve(i+1, j, grid, visited);
        solve(i-1, j, grid, visited);
        solve(i, j+1, grid, visited);
        solve(i, j-1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1' && !visited[i][j]){
                    solve(i, j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};