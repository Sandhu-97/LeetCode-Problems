class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allow;
        for (char c: allowed) allow.insert(c);
        int count=0;
        for (auto word: words){
            bool flag=true;
            for (char c: word){
                if (allow.count(c)==0) flag=false;
            }
            if (flag) count++;
        }
        return count;
    }
};