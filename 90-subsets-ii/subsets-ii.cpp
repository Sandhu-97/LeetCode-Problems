class Solution {
public:

    vector<vector<int>> res;

    void solve(int i, vector<int>& temp, vector<int>& nums){
        res.push_back(temp);

        for(int index=i;index<nums.size();index++){
            if (index>i && nums[index]==nums[index-1]) continue;

            temp.push_back(nums[index]);
            solve(index+1, temp, nums);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, nums);
        return res;
    }
};