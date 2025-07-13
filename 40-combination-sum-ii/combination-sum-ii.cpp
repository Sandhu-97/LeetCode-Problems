class Solution {
public:
    set<vector<int>> st;
    void solve(int i, int target ,vector<int>& temp, vector<vector<int>>& res, const vector<int>& candidates){
        if (target==0) {
            if (st.count(temp)==0){
                res.push_back(temp);
                st.insert(temp);
            } 
            return;
        }

        if (i>=candidates.size() || target<0) {
            return;
        }

        for (int j=i;j<candidates.size();j++){
            if (j>i && candidates[j]==candidates[j-1]) continue;
            temp.push_back(candidates[j]);
            solve(j+1, target-candidates[j], temp, res, candidates);
            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, target, temp, res, candidates);
        return res;
    }
};