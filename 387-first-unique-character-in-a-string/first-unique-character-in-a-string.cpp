class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        unordered_map<char, int> mp;
        for (char c: s) mp[c]++;
        for (auto it: mp){
            if (it.second==1){
                ans = min(ans, (int)s.find(it.first));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};