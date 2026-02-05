class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i=0;i<n;i++){
            int val = nums[i];
            
            int idx = ((i+val)%n + n) %n;

            result[i] = nums[idx];
        }
        return result;
    }
};