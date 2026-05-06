class Solution {
public:
    vector<string> ans;
    string curr;
    void solve(int n, int open, int close){
        if (curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if (open<n){
            curr.push_back('(');
            solve(n, open+1, close);
            curr.pop_back();
        }
        if (close<open){
            curr.push_back(')');
            solve(n, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0);
        return ans;
    }
};