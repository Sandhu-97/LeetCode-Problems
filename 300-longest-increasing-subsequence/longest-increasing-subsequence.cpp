class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& nums){
        if (dp[i]!=-1) return dp[i];

        int lis=1;

        for (int j=i+1;j<nums.size();j++){
            if (nums[i]<nums[j]){
                lis = max(lis, 1+ solve(j, nums));
            }
        }
        return dp[i] = lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        int ans = 0;
        for (int i=0;i<n;i++){
            ans = max(ans, solve(i, nums));
        }

        return ans;
    }
};