class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        vector<int> mp(26, 0);
        for (char c: s) mp[c-'a']++;
        for (int i=0;i<26;i++){
            if (mp[i]==1){
                ans= min(ans, (int)s.find(i+'a'));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};