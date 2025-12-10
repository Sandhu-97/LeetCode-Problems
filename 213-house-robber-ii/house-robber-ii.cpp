class Solution {
public:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if (i>n) return 0;
        if (dp[i]!=-1) return dp[i];
        
        int rob = nums[i] + solve(i+2, n, nums, dp);
        int leave = solve(i+1, n, nums, dp);

        return dp[i] = max(rob, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n, -1), dp2(n, -1);
        return max(solve(0, n-2, nums, dp1), solve(1, n-1, nums, dp2));

    }
};