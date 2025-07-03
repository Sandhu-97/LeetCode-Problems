class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0, right=0;
        int n=nums.size();
        int product=1, ans=0;

        for (right=0;right<n;right++){
            product *= nums[right];

            while (product>=k && left<=right) product/=nums[left++];
            ans+= (right-left+1);

        }
        return ans; 
    }
};