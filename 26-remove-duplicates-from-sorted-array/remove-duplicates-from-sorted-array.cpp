class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1;
        int n=nums.size();

        for (int right=left;right<n;right++){
            if (nums[left-1]!=nums[right]) nums[left++] = nums[right];
        }
        return left;
    }
};