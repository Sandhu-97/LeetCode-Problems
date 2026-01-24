class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, vector<int>& cost){
        if (i>=n) return 0;
        if (dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(solve(i+1, cost), solve(i+2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n+1, -1);
        int solve1 = solve(0, cost);
        int solve2 = solve(1, cost);
        return min(solve1, solve2);

    }
};