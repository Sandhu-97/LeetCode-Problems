class Solution {
public:

    void solve(vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){

        if (nums.size()==0){
            ans.push_back(temp);
            return;
        }

        for (int i=0;i<nums.size();i++){
            int elem = nums[i];
            temp.push_back(elem);
            nums.erase(nums.begin()+i);
            solve(temp, ans, nums);
            temp.pop_back();
            nums.insert(nums.begin()+i, elem);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp, ans, nums);
        return ans;
    }
};