class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums){
        if (nums.size()==0) {
            ans.insert(temp);
        }

        for (int i=0;i<nums.size();i++){
            int curr = nums[i];
            nums.erase(nums.begin()+i);
            temp.push_back(curr);
            solve(nums);
            temp.pop_back();
            nums.insert(nums.begin()+i, curr);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};