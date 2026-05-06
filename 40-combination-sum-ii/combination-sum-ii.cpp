class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int start, vector<int>& candidates, int target){
        if (target==0){
            ans.push_back(curr);
            return;
        }

        for (int i=start;i<candidates.size();i++){
            if (candidates[i]>target) break;
            if (i>start && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return ans;
    }
};