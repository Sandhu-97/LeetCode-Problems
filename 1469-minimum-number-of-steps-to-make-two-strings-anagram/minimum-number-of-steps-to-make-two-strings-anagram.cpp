class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> counts(26, 0);
        vector<int> countt(26, 0);
        for (char c: s) counts[c-'a']++;
        for (char c: t) countt[c-'a']++;
        int ans=0;
        for (int i=0;i<26;i++){
            ans+=abs(counts[i]-countt[i]);
        }
        return ans/2;
    }
};