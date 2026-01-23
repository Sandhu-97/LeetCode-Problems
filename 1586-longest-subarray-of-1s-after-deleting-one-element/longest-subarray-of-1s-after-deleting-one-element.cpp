class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, right=0, n=nums.size();
        int ans = 0, zero=0;

        while (right<n){
            if (nums[right]==0) zero++;

            while (zero>1){
                if (nums[left]==0) zero--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans-1;
    }
};