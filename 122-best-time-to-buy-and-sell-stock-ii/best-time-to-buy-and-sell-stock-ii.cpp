class Solution {
public:
    int solve (int i, int state, int n,  vector<vector<int>>& dp, vector<int>& prices){
        if (i>=n) return 0;
        if (dp[i][state]!=-1) return dp[i][state];
        
        int state0=0, state1=0;
        if (state==0){
            int buy = -prices[i] + solve (i+1, 1, n, dp, prices);
            int skip = solve(i+1, 0, n, dp, prices);
            state0=max(buy, skip);
        }
        if (state==1){
            int sell = +prices[i] + solve(i+1, 0, n, dp, prices);
            int hold = solve(i+1, 1, n, dp, prices);
            state1 = max(sell, hold);
        }

        return dp[i][state] = max(state0, state1);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int> (2, -1));
        int ans =  solve(0, 0, n, dp, prices);
        return ans;
        
    }
};