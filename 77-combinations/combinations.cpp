class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
    void solve(int i, int k){
        if (k==0){
            ans.push_back(curr);
            return;
        }

        for (;i<=n;i++){
            curr.push_back(i);
            solve(i+1, k-1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int N, int k) {
        n=N;
        solve(1, k);
        return ans;
    }
};