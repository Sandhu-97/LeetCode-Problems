class Solution {
public:
    set<vector<int>> res;

    void solve(int i, vector<int>& curr, vector<int>& nums){
        if (i>=nums.size()) {
            res.insert(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(i+1, curr, nums);
        curr.pop_back();
        solve(i+1, curr, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(0, curr, nums);
        vector<vector<int>> ans;
        for (auto i: res){
            ans.push_back(i);
        }
        return ans;
    }
};