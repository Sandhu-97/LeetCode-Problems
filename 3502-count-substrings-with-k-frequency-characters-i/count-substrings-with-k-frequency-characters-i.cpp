class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left=0;
        vector<int> freq(26, 0);
        int good = 0;
        int ans = 0;
        for (int right=0;right<s.size();right++){
            freq[s[right]-'a']++;
            if (freq[s[right]-'a']==k) good++;
            while (good>0){
                freq[s[left]-'a']--;
                if (freq[s[left]-'a']==k-1) good--;
                left++;
            }
            ans+=left;
        }
        return ans;
    }
};