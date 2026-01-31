class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, int target){
        if (target==0){
            ans.push_back(temp);
            return;
        }
        for (int idx=i;idx<nums.size();idx++){
            if (nums[idx]>target) break;

            temp.push_back(nums[idx]);
            solve(idx, nums, target-nums[idx]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return ans;
    }
};