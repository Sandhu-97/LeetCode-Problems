class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0;
        int n = nums.size();
        int sum=0;
        int minlen=INT_MAX;

        while (right<n){
            sum+=nums[right];
            while (sum>= target){
                minlen = min(minlen, right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }

        return minlen==INT_MAX ? 0 : minlen;
    }
};