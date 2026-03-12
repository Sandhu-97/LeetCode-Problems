class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ans=-1;

        for (int i: nums){
            if (ans==-1){
                count=1;
                ans=i;
            }
            else if (i==ans) count++;
            else if (i!=ans) {
                count--;
                if (count<=0){
                    ans=-1;
                    count=0;
                }
            }
        }
        return ans;
    }
};