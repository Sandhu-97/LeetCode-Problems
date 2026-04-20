class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size()==0) return {};

        unordered_map<string, vector<string>> mp;

        for (string s: strs){
            vector<int> count(26, 0);
            for (char c: s){
                count[c-'a']++;
            }
            string key = "";
            for (int i: count){
                key+="#";
                key+=to_string(i);
            }

            if (mp.find(key)==mp.end()) mp[key]={};
            mp[key].push_back(s);
        }

        for (auto it: mp) ans.push_back(it.second);
        return ans;
    }
};