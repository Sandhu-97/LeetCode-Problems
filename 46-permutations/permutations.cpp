class Solution {
public:
    void solve(vector<int>& nums,  vector<int>& temp, vector<vector<int>>& ans){
        if (nums.size()==0){
            ans.push_back(temp);
            return;
        }

        for (int i=0;i<nums.size();i++){
            int curr = nums[i];
            temp.push_back(curr);
            nums.erase(nums.begin()+i);
            solve(nums,temp, ans);
            nums.insert(nums.begin()+i, curr);
            temp.pop_back();

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, ans);
        return ans;
    }
};