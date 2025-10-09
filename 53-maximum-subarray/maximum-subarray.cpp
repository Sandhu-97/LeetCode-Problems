class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;

        for (int i: nums){
            curr += i;

            if (curr>maxi) maxi=curr;

            if (curr<0) curr=0;
        }

        return maxi;
    }
};