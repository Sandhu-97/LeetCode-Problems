class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<char>>& matrix){
        if (i>=m || j>=n || matrix[i][j]=='0') return 0;
        if (dp[i][j]!=-1) return dp[i][j];

        int right = solve(i, j+1, matrix);
        int down = solve(i+1, j, matrix);
        int diag = solve(i+1, j+1, matrix);

        return dp[i][j] = 1 + min( {right, down, diag} );
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        int ans = 0;
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, solve(i, j, matrix));   
            }
        }
        return ans*ans;


    }
};