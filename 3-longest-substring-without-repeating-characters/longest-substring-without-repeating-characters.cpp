class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left =0, right=0;
        int maxlen = 0;
        unordered_map<char, int> mp;
        for (right=0;right<n;right++){
            mp[s[right]]++;

            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }

            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};