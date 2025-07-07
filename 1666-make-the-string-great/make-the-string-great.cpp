class Solution {
public:
    string makeGood(string s) {
        if (s.size()==0) return "";
        string res;

        for (char c: s){
            // cout << res << endl;
            if (!res.empty() && (c-32==res.back() || c+32==res.back())) res.pop_back();
            else res.push_back(c);
            
        }
        return res;
    }
};