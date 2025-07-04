class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left=0, right=nums.size()-1;

        while (left<=right){
            int sq1 = nums[left]*nums[left];
            int sq2 = nums[right]*nums[right];

            if (sq1<=sq2){
                ans.push_back(sq2);
                right--;
            } 
            else if (sq1>sq2){
                ans.push_back(sq1);
                left++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};