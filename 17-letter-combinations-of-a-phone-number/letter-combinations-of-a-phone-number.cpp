class Solution {
public:
    vector<string> opt={
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> ans;
    void solve(int i, string digits, string& curr){
        if (i>=digits.size()){
            ans.push_back(curr);
            return;
        };

        int digit = digits[i]-'2';
        for (char option: opt[digit]){
            curr.push_back(option);
            solve(i+1, digits, curr);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        string curr="";
        solve(0, digits, curr);
        return ans;
    }
};