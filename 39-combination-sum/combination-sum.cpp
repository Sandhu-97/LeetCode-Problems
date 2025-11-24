class Solution {
public:

    void solve(int i, int target, vector<int>& curr, vector<vector<int>>& ans, vector<int>& candidates){
        if (target==0){
            ans.push_back(curr);
            return;
        }
        if (target<0) return;

        if (i>=candidates.size()) return;
        curr.push_back(candidates[i]);
        solve(i, target-candidates[i], curr, ans, candidates);
        curr.pop_back();
        solve(i+1, target, curr, ans, candidates);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, curr, ans, candidates);
        return ans;
    }
};