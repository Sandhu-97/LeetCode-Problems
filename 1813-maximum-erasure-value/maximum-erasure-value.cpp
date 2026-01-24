class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> map(10001, 0);
        int left=0, right=0;
        int sum=0, ans=0;
        while (right<nums.size()){
            map[nums[right]]++;
            sum += nums[right];
            while (map[nums[right]]>1){
                map[nums[left]]--;
                sum-=nums[left];
                left++;
            }

            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};