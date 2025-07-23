class Solution {
public:

    int rows, cols;

    bool isSafe(int row, int col, vector<vector<int>>& grid){
        return row>=0 && col>=0 && row<rows && col<cols && grid[row][col]==1;
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


        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                auto rotten = q.front();
                int row = rotten.first;
                int col = rotten.second;

                q.pop();

                for (int i=0;i<4;i++){
                    int new_row = row+dx[i];
                    int new_col = col+dy[i];

                    if (isSafe(new_row, new_col, grid)){
                        q.push({new_row, new_col});
                        grid[new_row][new_col] = 2;
                        fresh--;
                    }
                }
            }

            if (!q.empty()) minutes++;

        }

        return fresh==0? minutes: -1;
    }
};