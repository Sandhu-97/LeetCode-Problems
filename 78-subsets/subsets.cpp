class Solution {
public:

    void solve(int i, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if (i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, temp, ans, nums);
        temp.pop_back();
        solve(i+1, temp, ans, nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, temp, ans, nums);
        return ans;   
    }
};