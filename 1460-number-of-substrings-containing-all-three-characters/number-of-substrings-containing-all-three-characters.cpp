class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0;
        int ans=0, n=s.size();
        vector<int> mp(3, 0);

        while (right<n){
            mp[s[right]-'a']++;
            while (mp[0]>0 && mp[1]>0 && mp[2]>0 && left<=right){
                mp[s[left]-'a']--;
  
                left++;
            }
            ans+=left;
            right++;
        }
        return ans;
    }
};