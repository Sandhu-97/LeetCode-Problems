class Solution {
public:

    void solve (int open, int close, int n, string curr, vector<string>& res){
        if (open==n && close==n){
            res.push_back(curr);
            return;
        }

        if (open<n){
            curr.push_back('(');
            solve(open+1, close, n ,curr ,res);
            curr.pop_back();
        }
        if (close<open){
            curr.push_back(')');
            solve(open, close+1, n, curr, res);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        solve(0,0,n,curr,res);
        return res;
    }
};