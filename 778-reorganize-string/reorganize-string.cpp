class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c: s) freq[c]++;

        vector<char> sorted_chars;
        for (auto& pair: freq) sorted_chars.push_back(pair.first);
        sort(sorted_chars.begin(), sorted_chars.end(), [&](char a, char b) {
            return freq[a]>freq[b];
        });
        
        if (freq[sorted_chars[0]] > (s.size()+1)/2) return "";
        int i=0;
        string res(s.size(), ' ');
        for (char c: sorted_chars) {
            for (int j=0;j<freq[c];j++){
                if (i>=s.size()) i=1;
                res[i]=c;
                i+=2;
            }
        }
        return res;
    }
};