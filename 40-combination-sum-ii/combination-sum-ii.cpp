class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i, vector<int>& nums, int target){
        if (target==0){
            ans.push_back(temp);
            return;
        }
        for (int idx=i;idx<nums.size();idx++){
            if (nums[idx]>target) break;
            if (idx>i && nums[idx]==nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            solve(idx+1, nums, target-nums[idx]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end()); 
       solve(0, candidates, target);
       return ans;
    }
};