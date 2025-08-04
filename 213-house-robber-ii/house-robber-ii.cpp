class Solution {
public:
    // MEMOIZATION
    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if (i>n) return 0;
        if (dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + solve(i+2, n, nums, dp), solve(i+1,n,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        vector<int> dp(n, -1);

        int ans1 = solve(0, n-2, nums, dp);
        fill(dp.begin(), dp.end(), -1);
        int ans2 = solve(1, n-1, nums, dp);

        return max(ans1, ans2);
    }
};