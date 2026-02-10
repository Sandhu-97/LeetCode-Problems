class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> even, odd;
        int n = nums.size();
        int ans = 0;
        for (int i=0;i<n;i++){  
            even.clear(); odd.clear();

            for (int j=i;j<n;j++){
                if (nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(even.size()==odd.size()) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};