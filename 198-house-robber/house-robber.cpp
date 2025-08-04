class Solution {
public:
    // CONSTANT SPACE
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n==0) return 0;
        if (n==1) return nums[0];

        int prevprev = 0;
        int prev = nums[0];
        int profit = INT_MIN;
        for (int i=1;i<n;i++){
            profit = max(nums[i] + prevprev, prev); 
            prevprev = prev;
            prev = profit;
        }

        return prev;
    }
};