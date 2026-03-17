class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size()==1) return strs[0];
        sort(strs.begin(), strs.end());

        string ans = "";
        int n = strs.size();
        int i=0;
        if (strs[0].empty() || strs[n-1].empty()) return "";
        while (i< strs[0].size() && strs[0][i]==strs[n-1][i]){
            ans.push_back(strs[0][i]);
            i++;
        }
        return ans;
        
    }
};