class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        for (;i<n;i++){
            if (nums[i]!=0) {
                // nums[j++]=nums[i]; 
                swap(nums[j], nums[i]);
                j++;
            }
        }
        
    }
};