class Solution {
public:
    bool valid(string s){
        int left=0;
        int right=s.size()-1;
        while (left<right){
            if (s[left]!=s[right]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxi=0;
        string ans="";
        for (int i=0;i<s.size();i++){
            for (int j=i;j<s.size();j++){
                int l=i, r=j;
                while (l<r && s[l]==s[r]){
                    l++; r--;
                }
                if (l>=r && j-i+1>maxi){
                    ans = s.substr(i, j-i+1);
                    maxi = j-i+1;
                }
            }
        }
        return ans;

    }
};