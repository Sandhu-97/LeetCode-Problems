class Solution {
public:
    int t;
    int solve(int l, int h, vector<int>& nums){
        if (l>h) return -1;
        int mid=  (h+l)/2;
        if (nums[mid]==t) return mid;
        else if (nums[mid]>t) return solve(l, mid-1, nums);
        else return solve(mid+1, h, nums);
    }
    int search(vector<int>& nums, int target) {
        t = target;
        return solve(0,nums.size()-1, nums);
    }
};