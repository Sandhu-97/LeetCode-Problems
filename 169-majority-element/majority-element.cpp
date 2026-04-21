class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ans = nums[0];

        for (int i: nums){
            if (i==ans) count++;
            else if (i!=ans) count--;

            if (count<0){
                ans=i;
                count=0;
            }
        }
        return ans;
    }
};