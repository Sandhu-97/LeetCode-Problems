class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int left=0, right=0;
        int maxi=0, sum=0;

        for(;right<nums.size();right++){
            sum+=nums[right];
            mp[nums[right]]++;
            while (mp[nums[right]]>1){
                mp[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            maxi=max(maxi, sum);
        }

        return maxi;
    }
};