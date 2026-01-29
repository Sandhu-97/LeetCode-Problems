class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int target, vector<int>& nums){
        if (i>=nums.size()) return false;
        if (target==0) return true;
        if (target<0) return false;
        if (dp[i][target]!=-1) return dp[i][target];
        return dp[i][target]=solve(i+1, target, nums) || solve(i+1, target-nums[i], nums);
    }
    bool canPartition(vector<int>& nums) {
        int target=accumulate(nums.begin(), nums.end(), 0);
        if (target%2!=0) return false;
        target/=2;
        dp.assign(nums.size(), vector<int>(target+1, -1));
        return solve(0, target, nums);
    }
};