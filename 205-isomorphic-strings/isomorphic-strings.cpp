class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, ts;

        for (int i=0;i<s.size();i++){
            if (mp.find(s[i])==mp.end()) mp[s[i]]=t[i];
            else if (mp[s[i]]!=t[i]) return false;

            if (ts.find(t[i])==ts.end()) ts[t[i]]=s[i];
            else if (ts[t[i]]!=s[i]) return false;
            
                
        }
        return true;
    }
};