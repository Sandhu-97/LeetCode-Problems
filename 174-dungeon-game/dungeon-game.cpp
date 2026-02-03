class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& dungeon){
        if (i>=m || j>=n) return 1e9;

        if (i==m-1 && j==n-1){
            return max(1, 1-dungeon[i][j]);
        }

        if (dp[i][j]!=INT_MAX) return dp[i][j];
        int right = solve(i, j+1, dungeon);
        int down = solve(i+1, j, dungeon);
        int need = min(right, down) - dungeon[i][j];
        return dp[i][j]=max(1, need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        dp.assign(m, vector<int>(n, INT_MAX));
        return solve(0,0,dungeon);
    }
};