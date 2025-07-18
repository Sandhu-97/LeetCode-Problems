class Solution {
public:
    string processStr(string s) {
        string res;

        for (char c: s){
            if (isalpha(c)) res.push_back(c);
            if (c=='*' && !res.empty()) res.pop_back();
            if (c=='%') reverse(res.begin(), res.end());
            if (c=='#') res.append(res);
        }
        return res;
    }
};