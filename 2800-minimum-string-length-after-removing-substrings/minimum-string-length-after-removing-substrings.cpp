class Solution {
public:
    int minLength(string s) {
        string res;
        for (char c: s){
            
            if (c=='B' && res.size()>0 && res.back()=='A' ) res.pop_back();
            else if (c=='D' && res.size()>0 && res.back()=='C') res.pop_back();
            else res.push_back(c);
        }
        return res.size();
    }
};