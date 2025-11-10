class Solution {
public:

    bool solve(int i, long long p1, long long p2, long long target, vector<int>& nums){
        if (p1>target || p2 > target) return false;
        if (i==nums.size()) return p1==target && p2==target;
        bool a = solve(i+1, p1*nums[i], p2, target, nums);
        bool b = solve(i+1, p1, p2*nums[i], target, nums);
        return a | b;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(0, 1, 1, target, nums);
    }
};