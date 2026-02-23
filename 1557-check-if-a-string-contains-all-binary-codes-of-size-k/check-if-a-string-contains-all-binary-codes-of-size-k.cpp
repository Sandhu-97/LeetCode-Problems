class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();

        unordered_set<string> codes;

        for (int i=0;i+k<=n;i++){
            string sub = s.substr(i, k);
            codes.insert(sub);
            if (codes.size()==(1<<k)) return true;
        }
        return false;
    }
};