class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, n= nums.size();
        int maxlen=0;
        int count=0;

        for (right=0;right<n;right++){
            if (nums[right]==0) count++;
            while (count>k){
                if (nums[left]==0) count--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};