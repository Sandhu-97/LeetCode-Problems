class Solution {
public:
    vector<int> dp;
    int n;
    int solve (int i, vector<int>& nums){
        if (i>=n) return 0;

        if (dp[i]!=-1) return dp[i];
        int rob=nums[i]+solve(i+2, nums);
        int leave=solve(i+1, nums);

        return dp[i]=max(rob, leave);
            
        
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
};