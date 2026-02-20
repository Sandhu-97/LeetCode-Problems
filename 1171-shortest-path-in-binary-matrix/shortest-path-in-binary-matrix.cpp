class Solution {
public:
    int n;
    bool valid (int i, int j, vector<vector<int>>& grid){
        if (i<0 || j<0 || i>= n || j>=n || grid[i][j]!=0) return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0]!=0) return -1;
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<int>> dir = {
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
                    if (valid(nrow, ncol, grid)){
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