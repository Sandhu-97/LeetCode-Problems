class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, vector<int>& curr, vector<int>& nums){
        if (i>=nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1, curr, nums);
        curr.pop_back();
        solve(i+1, curr, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0, curr, nums);
        return res;
    }
};