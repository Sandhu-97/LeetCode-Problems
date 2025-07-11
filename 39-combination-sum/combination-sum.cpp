class Solution {
public:

    void solve(int i, vector<int>& candidates,vector<int>& temp, vector<vector<int>>& res, int target){
        if (target==0){
            res.push_back(temp);
            return;
        }
        if (target<0){
            return;
        }
        if (i>=candidates.size()) return;
        temp.push_back(candidates[i]);
        solve(i, candidates, temp, res, target-candidates[i]);
        temp.pop_back();
        solve(i+1, candidates, temp, res, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(0, candidates,temp, res, target);
        return res;
    }
};