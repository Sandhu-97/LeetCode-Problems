class Solution {
public:
    int helper (int i, int j, string s){
        int count=0;
        while (i>=0 && j <s.size() && s[i]==s[j]){
            count++;
            i--; j++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        for (int i=0;i<s.size();i++){
            count += helper(i,i,s);
            count += helper(i, i+1, s);
        }
        return count;
    }
};