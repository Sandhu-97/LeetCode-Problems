class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        int count=0;
        for (auto word: words){
            bool flag=true;
            for (char c: word){
                if (allowed.find(c)==string::npos) flag=false;
            }
            if (flag) count++;
        }
        return count;
    }
};