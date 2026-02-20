class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int dir[8][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        int ans = 1;
        while (!q.empty()){
            int size=q.size();

            while (size--){
                auto [r, c] = q.front(); q.pop();

                if (r==n-1 && c==n-1) return ans;
                for (auto d: dir){
                    int nrow = r+d[0];
                    int ncol = c+d[1];
                    if (nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0){
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};