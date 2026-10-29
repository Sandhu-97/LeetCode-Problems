class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,n=nums.size();

        for (;i<n;i++){
            if (nums[i]==nums[i-1]) continue;
            nums[j++] = nums[i];
        }
        return j;
    }
};