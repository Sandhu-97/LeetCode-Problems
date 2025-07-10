class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i: nums) mp[i]++;
        int count=0;
        for (auto i: mp){
            if (i.second==1) return -1;
            count+=ceil((double)i.second/3);
        }
        return count;
    }
};