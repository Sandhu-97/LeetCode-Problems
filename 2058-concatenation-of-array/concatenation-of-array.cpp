class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        nums.resize(n+n);
        for (int i=n;i<2*n;i++){
            nums[i]=nums[i-n];
        }
        return nums;
    }
};