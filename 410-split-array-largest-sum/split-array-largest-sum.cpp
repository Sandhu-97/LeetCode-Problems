class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low<=high){
            int mid = low+(high-low)/2;
            int pieces=1;
            int sum=0;
            for (int i:nums){
                if (sum+i>mid){
                    pieces++;
                    sum=0;
                }
                sum+=i;
            }

            if (pieces<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};