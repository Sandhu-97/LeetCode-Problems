class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for (int i: nums) sum+=i;
        int leftsum = 0;
        for (int& i: nums){
            int rightsum = sum-leftsum-i;
            int temp = leftsum;
            leftsum+=i;
            i=abs(temp-rightsum);
        }
        return nums;
    }
};