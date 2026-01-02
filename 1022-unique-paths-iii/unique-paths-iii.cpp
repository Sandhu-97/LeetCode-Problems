class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void solve(int i, int j, int m, int n, int& count, int remain, vector<vector<int>>& grid){
        if (i>=m || i<0 || j>=n || j<0 || grid[i][j]==-1) return;
        if (grid[i][j]==2){
            if (remain==1) count++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        for (int k=0;k<4;k++){
            solve(i+ dx[k], j+ dy[k], m, n, count, remain-1, grid);
        }
        grid[i][j]=temp;


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty, endx, endy;
        int m = grid.size();
        int n = grid[0].size();
        int remain = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1) {
                    startx = i;
                    starty = j;
                }
                if (grid[i][j]!=-1) remain++;
            }
        }

        int count = 0;
        solve(startx, starty, m, n, count, remain, grid);
        return count;

    }
};