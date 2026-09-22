class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> bfs;
        vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i=0;i<m;i++){
            if (grid[i][0]==1) {
                bfs.push({i, 0});
                grid[i][0]=2;
            }
            if (grid[i][n-1]==1) {
                bfs.push({i, n-1});
                grid[i][n-1]=2;
            }
        }
        for (int j=0;j<n;j++){
            if (grid[0][j]==1) {
                bfs.push({0, j});
                grid[0][j]=2;
            }
            if (grid[m-1][j]==1) {
                bfs.push({m-1, j});
                grid[m-1][j]=2;
            }
        }

        while (!bfs.empty()){
            auto [i,j] = bfs.front(); bfs.pop();

            for (auto dir: dirs){
                int newi = dir[0]+i;
                int newj = dir[1]+j;

                if (newi<0 || newj<0 || newi>=m || newj >= n || grid[newi][newj]!=1) continue;
                bfs.push({newi, newj});
                grid[newi][newj]=2;
            };
        }

        int ans=0;
        for (auto row: grid){
            for (int col: row){
                if (col==1) ans++;
            }
        }
        return ans;


    }
};