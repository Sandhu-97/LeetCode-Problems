class Solution {
public:
    // TABULATION
    int solve(int i, int n, vector<int>& nums){
        int len = n-i+1;

        if (len==1) return nums[i];
        vector<int> dp(len+1, 0);
        dp[0] = 0;
        dp[1] = nums[i];

        for (int k=2;k<=len;k++){
            dp[k] = max(dp[k-1], nums[i+k-1] + dp[k-2]);
        }

        return dp[len];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        int ans1 = solve(0, n-2, nums);
        int ans2 = solve(1, n-1, nums);

        return max(ans1, ans2);
    }
};