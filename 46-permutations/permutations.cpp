class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums){
        if (nums.size()==0) {
            ans.push_back(temp);
            return;
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
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums);
        return ans;
    }
};