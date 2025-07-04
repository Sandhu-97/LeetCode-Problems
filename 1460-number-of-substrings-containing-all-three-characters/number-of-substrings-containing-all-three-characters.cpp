class Solution {
public:
    int numberOfSubstrings(string s) {
        int maxi = 0;
        int left=0, right=0;
        unordered_map<char, int> mp;
        int n = s.size();
        for (right=0;right<n;right++){
            mp[s[right]]++;

            while (mp['a']>0 && mp['b']>0 && mp['c']>0 && left<=right){
                maxi += (n-right);
                mp[s[left]]--;
                left++;
            }
        }
        return maxi;
    }
};