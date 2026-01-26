class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, string s){
        if (i>=n) return 1;
        if (s[i]=='0') return 0;
        if (dp[i]!=-1) return dp[i];
        int ways = solve(i+1, s);
        if(i+1<n){
            if (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                ways+=solve(i+2, s);
            }
        }
        return dp[i]=ways;

    }
    int numDecodings(string s) {
        n=s.size();
        dp.assign(n+1, -1);
        return solve(0, s);
    }
};