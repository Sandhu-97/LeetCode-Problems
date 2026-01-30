class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, vector<int>& temp){
        ans.push_back(temp);

        for (int idx=i;idx<nums.size();idx++){
            if (idx>i && nums[idx-1]==nums[idx]) continue;
            temp.push_back(nums[idx]);
            solve(idx+1, nums, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp);
        return ans;
    }
};