class Solution {
public:

    int houseRobberI(vector<int>& nums, vector<int>& dp){
        int n = nums.size();

        if (n==0) return 0;
        if (n==1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i=2;i<n;i++){
            int rob = nums[i]+dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(rob, skip);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());

        vector<int> dp1(n-1, -1), dp2(n-1, -1);

        return max(houseRobberI(nums1, dp1),  houseRobberI(nums2, dp2));

    }
};