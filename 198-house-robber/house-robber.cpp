class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& dp){
        if (i>=nums.size()){
            return 0;
        }


        if (dp[i]!=-1) return dp[i];


        dp[i] = nums[i] + solve(i+2, nums, dp);
        dp[i+1] = solve(i+1, nums, dp);

        return max(dp[i], dp[i+1]);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(0, nums, dp);
    }
};