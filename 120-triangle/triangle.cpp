class Solution {
public:
    int m;
    vector<vector<int>> dp;
    int solve (int i, int j, vector<vector<int>>& triangle){
        if (i>=m) return 0;
        if (j<0 || j>=triangle[i].size()) return 1e5;
        if (dp[i][j]!=INT_MAX) return dp[i][j];
        int path1 = solve(i+1, j, triangle);
        int path2 = solve(i+1, j+1, triangle);

        return dp[i][j] = triangle[i][j] + min(path1, path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        dp.assign(m, vector<int>(0));
        for (int i=0;i<m;i++){
            dp[i].resize(triangle[i].size(), INT_MAX);
        }
        return solve(0,0,triangle);
    }
};