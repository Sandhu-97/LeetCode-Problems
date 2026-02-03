class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int n = nums.size();
        while (p+1<n && nums[p]<nums[p+1]) p++;
        if (p==0) return false;
        int q=p;
        while (q+1<n && nums[q+1]<nums[q]) q++;
        if (p==q) return false;
        int r = q;
        while (r+1<n && nums[r]<nums[r+1]) r++;
        if (r==q) return false;
        return r==n-1;
    }
};