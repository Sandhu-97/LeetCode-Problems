class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,
        right=0;

        for (;right<nums.size();right++){
            if (nums[right]==val) continue;
            nums[left++]=nums[right];
        }
        return left;
    }
};