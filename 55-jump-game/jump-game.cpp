class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(int i, vector<int>& nums){
        if (i>=n-1) return true;
        int jumps = nums[i];
        if (dp[i]!=-1) return dp[i];
        bool ans = false;
        for (int j=1;j<=jumps;j++){
            ans = ans || solve(i+j, nums);
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        dp.assign(n+1, -1);
        return solve(0, nums);
    }
};