class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color) return image;
        int source = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});

        int m = image.size();
        int n = image[0].size();

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};
        while (!q.empty()){
            auto [i,j] = q.front(); q.pop();
            image[i][j] = color;
            for (int k=0;k<4;k++){
                int nr = i+dx[k];
                int nc = j+dy[k];
                if (nr<0 || nc <0 || nr>=m || nc >= n || image[nr][nc]!=source) continue;
                if (image[nr][nc]==source) q.push({nr, nc});
            }
        }
        return image;
    }
};