class Solution {
public:
    void solve(int i, int& n, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if (i==n){
            ans.push_back(temp);
            return;
        }
        solve(i+1, n, temp, ans, nums);
        temp.push_back(nums[i]);
        solve(i+1, n, temp, ans, nums);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(0, n, temp, ans, nums);
        return ans;
    }
};