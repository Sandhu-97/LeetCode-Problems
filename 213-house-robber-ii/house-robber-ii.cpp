class Solution {
public:

    // CONSTANT SPACE

    int solve(int i, int n, vector<int>& nums){
        int len = n-i+1;
        if (len==1) return nums[i];
        int prev = nums[i];
        int prevprev = 0;
        int profit = INT_MIN;
        for (int k=i+1;k<=n;k++){
            profit = max(prev, prevprev+nums[k]);
            prevprev = prev;
            prev = profit;
        }

        return profit;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        int ans1 = solve(0, n-2, nums);
        int ans2 = solve(1, n-1, nums);

        return max(ans1, ans2);
    }
};