class Solution {
public:

    int N;
    vector<vector<int>> dir = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    double dp[26][26][101];
    bool valid(int row, int col){
        if (row>=N || row<0 || col >=N || col<0) return false;
        return true;
    }
    double solve(int row, int col, int k){
        if(!valid(row, col)) return 0.0;
        if (k==0) return 1.0;
        if (dp[row][col][k]!=-1.0) return dp[row][col][k];
        double prob = 0;
        for (auto i: dir){
            prob += solve(row+i[0], col+i[1], k-1);
        }
        return dp[row][col][k] = prob/8.0;


    }
    double knightProbability(int n, int k, int row, int column) {
        N=n;
        for (int i=0;i<26;i++){
            for (int j=0;j<26;j++){
                for (int k=0;k<101;k++) dp[i][j][k] = -1.0;
            }
        }
        double ans = solve(row, column, k);
        return ans;
    }
};