class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size()==1) return 1;
        if (nums.size()==2 && nums[1]== nums[0]) return 1;
        sort(nums.begin(), nums.end()); 
        int maxi=1;
        int n = nums.size();
        int count = 1;
        for(int i=1;i<n;i++){
            if (nums[i]==nums[i-1]) continue;
            if (nums[i]==nums[i-1]+1){
                count++;
            }
            else {
                maxi = max(count, maxi);
               count=1;
            }
        }
        return max(maxi, count);
    }
};