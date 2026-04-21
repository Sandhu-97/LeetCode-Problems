class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n= min(word1.size(), word2.size());
        int i=0, j=0;
        for (i=0, j=0;i<n && j<n;i++, j++){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
        }
        while (i<word1.size()){
            ans.push_back(word1[i++]);
        }

        while (j<word2.size()){
            ans.push_back(word2[j++]);
        }

        return ans;
        
    }
};