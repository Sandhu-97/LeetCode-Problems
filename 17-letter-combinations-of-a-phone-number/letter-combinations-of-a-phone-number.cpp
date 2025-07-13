class Solution {
public:

    void solve(int i, unordered_map<char, string>& mp, string& curr, vector<string>& res, string& digits){
        if (i>= digits.size()) {
            res.push_back(curr);
            return;
        }

        char current = digits[i];
        string options = mp[current];

        for (char c: options){
            curr.push_back(c);
            solve(i+1, mp, curr, res, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        

        vector<string> res;
        string curr;
        solve(0, mp, curr, res, digits);
        return res;
    }
};