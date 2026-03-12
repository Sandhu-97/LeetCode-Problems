class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, ans=-10000;

        for (int i: nums){
            sum+=i;
            if (sum>ans) ans=sum;
            if (sum<0) sum=0;
        }

        return ans;
    }
};