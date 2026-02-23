class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<vector<int>> mp(26, vector<int>(2, 0));

        for (int i=0;i<s.size();i++){
            mp[s[i]-'a'][0] = i;
        }

        for (int i=0;i<t.size();i++) mp[t[i]-'a'][1]=i;

        int sum = 0;
        for (int i=0;i<26;i++){
            sum += abs(mp[i][0]-mp[i][1]);
        }
        return sum;
    }
};