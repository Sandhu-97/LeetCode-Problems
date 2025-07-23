class Solution {
public:

    int rows, cols;

    bool isSafe(int row, int col, vector<vector<int>>& grid){
        if (row<0 || col<0 || row>=rows || col>=cols || grid[row][col]!=1) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh=0;

        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j]==1) fresh++;
            }
        }

        int minutes = 0;

        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                auto rotten = q.front();
                int row = rotten.first;
                int col = rotten.second;

                q.pop();


                if (isSafe(row+1, col, grid)) {
                    grid[row+1][col] = 2;
                    q.push({row+1, col});
                    fresh--;
                }
                if (isSafe(row-1, col, grid)) {
                    grid[row-1][col] = 2;
                    q.push({row-1, col});
                    fresh--;
                }
                if (isSafe(row, col+1, grid)) {
                    grid[row][col+1] = 2;
                    q.push({row, col+1});
                    fresh--;
                }
                if (isSafe(row, col-1, grid)) {
                    grid[row][col-1] = 2;
                    q.push({row, col-1});
                    fresh--;
                }
            }

            if (!q.empty()) minutes++;

        }

        return fresh==0? minutes: -1;
    }
};