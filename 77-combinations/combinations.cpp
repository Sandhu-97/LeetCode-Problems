class Solution {
public:

    void solve(int i, const int& n,const int& k, vector<int>& temp, vector<vector<int>>& res){
        if (temp.size()==k){
            res.push_back(temp);
            return;
        }

        for (int j=i;j<=n;j++){
            temp.push_back(j);
            solve(j+1, n ,k ,temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1,n,k,temp,res);
        return res;
    }
};