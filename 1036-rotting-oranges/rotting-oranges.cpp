class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh=0, time=0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                switch (grid[i][j]) {
                    case 1:
                    fresh++;
                    break;
                    
                    case 2:
                    rotten.push({i,j});
                    break;

                    default:
                    break;
                }
            }
        }

        while (!rotten.empty()){
            int size = rotten.size();
            while (size--){
                auto [i,j] = rotten.front(); rotten.pop();
                for (int k=0;k<4;k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];

                    if (nr>=0 && nc >= 0 && nr<m && nc< n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        rotten.push({nr, nc});
                    }
                }
            }
            if (!rotten.empty()) time++;
        }
        return fresh==0?time:-1;
    }
};