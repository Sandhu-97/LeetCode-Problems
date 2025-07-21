class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        for (char c: stones) mp[c]++;
        int count=0;
        for (char c: jewels){
            if (mp.find(c)!=mp.end()) count+=mp[c];
        }
        return count;
    }
};