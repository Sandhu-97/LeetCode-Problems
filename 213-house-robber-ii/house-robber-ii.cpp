class Solution {
public:


    // MEMOIZATION
    int solve(int i, int end, vector<int>& nums, vector<int>& dp){
        if (i>end) return 0;

        if (dp[i]!=-1) return dp[i];

        int rob = nums[i]+solve(i+2, end, nums, dp);
        int skip = solve(i+1, end, nums, dp);

        return dp[i]=max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        
        vector<int> dp1(n, -1), dp2(n, -1);

        int opt1 = solve(0, n-2, nums, dp1);
        int opt2 = solve(1, n-1, nums, dp2);

        return max(opt1, opt2);

    }
};