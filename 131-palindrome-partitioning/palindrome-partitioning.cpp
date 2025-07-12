class Solution {
public:


    bool valid (string s){
        int left=0, right=s.size()-1;

        while (left<right){
            if (s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(vector<string>& curr, vector<vector<string>>& res, string s){
        if (s.size()==0){
            res.push_back(curr);
            return;
        }
        for (int i=0;i<s.size();i++){
            string part = s.substr(0, i+1);
            if (valid(part)){
                curr.push_back(part);
                solve(curr, res, s.substr(i+1));
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        solve(curr, res, s);
        return res;

    }
};