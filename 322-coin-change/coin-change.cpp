class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<int>& dp){
        if (amount==0) return 0;
        int ans = 1e9;
        if (dp[amount]!=-1) return dp[amount];
        for (int c:coins){
            if (amount-c>=0)
            ans = min(ans,1 + solve(amount-c, coins, dp));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans =solve(amount, coins, dp);
        return ans==1e9?-1:ans;
    }
};