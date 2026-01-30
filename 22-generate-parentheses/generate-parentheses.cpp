class Solution {
public:
    string temp;
    vector<string> ans;
    int N;
    void solve(int open, int close){
        if (temp.size()==2*N){
            ans.push_back(temp);
            return;
        }

        if (open<N){
            temp.push_back('(');
            solve(open+1, close);
            temp.pop_back();
        }
        if (close<open){
            temp.push_back(')');
            solve(open, close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        solve(0, 0);
        return ans;
    }
};