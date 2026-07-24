class Solution {
public:
    int old_color, new_color, m, n;
    void solve(int i, int j, vector<vector<int>>& image){
        if (i<0 || j<0 || i>=m || j>=n || image[i][j]!=old_color) return;
        image[i][j]=new_color;
        solve(i+1, j, image);
        solve(i-1, j, image);
        solve(i, j+1, image);
        solve(i, j-1, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size(), n=image[0].size();
        old_color = image[sr][sc];
        new_color = color;
        if (old_color==new_color) return image;
        solve(sr,sc,image);
        return image;
    }
};