class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1,
        right=1;

        for(;right<nums.size();right++){
            if (nums[right]==nums[right-1]) continue;
            nums[left++]=nums[right];
        }
        return left;
    }
};