class Solution {
public:

    int solve(int i, int n, vector<int>& dp, vector<int>& nums){
        if (i>=n) return 0;
        if (dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(i+2, n, dp, nums);
        int leave = solve(i+1, n, dp, nums);
        return dp[i] = max(steal, leave);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, dp, nums);
        
    }
};