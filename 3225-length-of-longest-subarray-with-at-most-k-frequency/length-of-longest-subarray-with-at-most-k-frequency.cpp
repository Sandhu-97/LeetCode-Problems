class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0, right=0, n = nums.size();
        int maxlen=0;
        unordered_map<int, int> mp;

        for (right=0;right<n;right++){
            mp[nums[right]]++;
            while (mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};