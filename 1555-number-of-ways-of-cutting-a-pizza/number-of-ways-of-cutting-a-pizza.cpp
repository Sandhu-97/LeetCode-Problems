class Solution {
public:
    static const int mod = 1e9+7;
    int R, C;
    vector<vector<int>> apples;
    int dp[51][51][11];

    int hasApple(int r, int c){
        return apples[r][c]>0;
    }

    int solve(int r, int c, int cuts){
        if (!hasApple(r, c)) return 0;
        if (cuts==0) return 1;

        int& res = dp[r][c][cuts];
        if (res!=-1) return res;

        long long ans = 0;

        for (int nr=r+1;nr<R;nr++){
            if (apples[r][c]-apples[nr][c]>0){
                ans = (ans+solve(nr, c, cuts-1)) % mod;
            }
        }
        for (int nc=c+1;nc<C;nc++){
            if (apples[r][c]-apples[r][nc]>0){
                ans = (ans+solve(r, nc, cuts-1)) % mod;
            }
        }
        return res=ans;
    }

    int ways(vector<string>& pizza, int k) {
        R=pizza.size();
        C=pizza[0].size();

        apples.assign(R+1, vector<int>(C+1, 0));

        for (int r=R-1; r>=0;r--){
            for (int c=C-1; c>=0;c--){
                apples[r][c] = apples[r+1][c] + apples[r][c+1] - apples[r+1][c+1] + (pizza[r][c]=='A');
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0,0,k-1);
    }
};