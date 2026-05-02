class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums){
        if (nums.empty()){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            nums.erase(nums.begin()+i);
            curr.push_back(temp);
            solve(nums);
            curr.pop_back();
            nums.insert(nums.begin()+i, temp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums);
        return ans;
    }
};