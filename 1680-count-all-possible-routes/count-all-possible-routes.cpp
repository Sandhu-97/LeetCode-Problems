class Solution {
public:
    static const int mod = 1e9+7;
    vector<int> loc;
    vector<vector<int>> dp;
    int n, fin;

    int solve(int city, int fuel){
        if (fuel<0) return 0;
        if (dp[city][fuel]!=-1) return dp[city][fuel];
        long long ans=0;
        if (city==fin) ans=1;
        for (int i=0;i<n;i++){
            if (city==i) continue;
            int cost = abs(loc[i]-loc[city]);
            if (fuel>=cost){
                ans = (ans+solve(i, fuel-cost))%mod;
            }
        }
        return dp[city][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        loc = locations;
        n=loc.size();
        fin = finish;
        dp.assign(n, vector<int>(fuel+1, -1));
        return solve(start, fuel);
    }
};