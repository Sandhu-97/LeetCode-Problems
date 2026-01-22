class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), count=0, maxi=0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            nums[i]==0?count--:count++;
            if (mp.count(count)){
                maxi = max(maxi, i-mp[count]);
            }
            else mp[count]=i;
        }
        return maxi;
    }
};