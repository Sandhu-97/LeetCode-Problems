class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left=0, right=0;
        int ans = 0;
        
        for  (;right<n;right++){

            while ((long long)nums[left]*k < (long long)nums[right]) left++;
            ans = max(ans, right-left+1);
        }
        return n-ans;
    }
};