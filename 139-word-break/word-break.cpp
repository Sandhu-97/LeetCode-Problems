class Solution {
public:
    vector<int> dp;
    bool solve(int i, string s, vector<string>& dict){
        if (i>=s.size()) return true;
        if (dp[i]!=-1) return dp[i];
        for (string word: dict){
            if (i+word.size()<=s.size() && s.substr(i, word.size()) == word){
                if (solve(i+word.size(), s, dict)){
                    dp[i] = 1;
                    return true;
                }
            }
        }
        dp[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size()+1, -1);
        return solve(0, s, wordDict);
    }
};