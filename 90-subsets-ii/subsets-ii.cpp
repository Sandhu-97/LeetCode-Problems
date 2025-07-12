class Solution {
public:

    vector<vector<int>> res;

    void solve(int i, vector<int>& temp, vector<int>& nums){
        if (i>=nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, temp, nums);
        temp.pop_back();


        int index = i+1;
        while (index<nums.size() && nums[index]==nums[index-1]) index++;

        solve(index, temp, nums);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, nums);
        return res;
    }
};