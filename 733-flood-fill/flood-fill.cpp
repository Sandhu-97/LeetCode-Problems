class Solution {
public:
    int start;
    int end;
    int m,n;
    void dfs(int i, int j, vector<vector<int>>& image){
        if (i<0 || j<0 || i>=m || j>=n || image[i][j]!=start) return;
        image[i][j] = end;

        dfs(i+1, j, image);
        dfs(i, j+1, image);
        dfs(i-1, j, image);
        dfs(i, j-1, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        start = image[sr][sc];
        end = color;
        m = image.size(), n=image[0].size();
        if (start==end) return image;
        dfs(sr,sc,image);
        return image;
    }
};