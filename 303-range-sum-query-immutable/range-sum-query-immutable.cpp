class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp.resize(nums.size());
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if (left==0) return dp[right];
        return dp[right]-dp[left-1];   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */