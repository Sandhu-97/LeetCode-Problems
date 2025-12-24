class Solution {
public:
    bool solve(int i, long long p1, long long p2, vector<int>& nums, long long target){

        if (p1==target && p2==target && nums.size()==i) return true;
        if (p1>target || p2>target || i>=nums.size()) return false;


        bool a = solve(i+1, p1*nums[i], p2, nums, target);
        bool b = solve(i+1, p1, p2*nums[i], nums, target);

        return a | b;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(0, 1, 1, nums, target);
    }
};