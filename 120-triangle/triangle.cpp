class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size()-1;

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int col=0;col<triangle[n].size();col++){
            dp[n][col] = triangle[n][col];
        }

        for (int row=n-1;row>=0;row--){
            for (int col=0;col<triangle[row].size();col++){
                dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }
};