class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;

        unordered_map<char, int> sfreq, tfreq;

        for (int i=0;i<s.size();i++){
            sfreq[s[i]]++;
            tfreq[t[i]]++;
        }
        return sfreq==tfreq;
    }
};