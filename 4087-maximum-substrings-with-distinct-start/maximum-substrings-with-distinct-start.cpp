class Solution {
public:
    int maxDistinct(string s) {
        vector<int> st(26, 0);
        for (char c: s) st[c-'a']++;
        int count=0;
        for (int i: st) if (i>=1) count++;
        return count; 
    }
};