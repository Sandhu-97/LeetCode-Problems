class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0, right=0;
        int n=nums.size();
        int product=1, ans=0;

        while (right<n){
            product *= nums[right];

            while (product>=k && left <=right){
                product/=nums[left];
                left++;
            }
            ans+= (right-left+1);

            right++;
        }
        return ans; 
    }
};