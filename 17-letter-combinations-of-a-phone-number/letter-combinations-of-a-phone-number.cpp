class Solution {
public:
    unordered_map<char, string> mp;
    int n;
    string temp;
    vector<string> ans;

    void solve(int i, string digits){
        if (i>=n){
            ans.push_back(temp);
            return;
        }

        string curr = mp[digits[i]];
        for (char c: curr){
            temp.push_back(c);
            solve(i+1, digits);
            temp.pop_back();
        }

        
    }
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        n=digits.size();
        solve(0, digits);
        return ans;
    }
};