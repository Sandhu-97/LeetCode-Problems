class Solution {
public:
    int dp[2500];
    int solve(int i, vector<int>& nums){
        if (dp[i]!=-1) return dp[i];
        int maxlength = 1;
        for (int idx=i-1;idx>=0;idx--){
            if (nums[i] > nums[idx]){
                int length = 1 + solve(idx, nums);
                maxlength = max(maxlength, length);
            }
        }
        return dp[i] =  maxlength;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i=0;i<nums.size();i++){
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};