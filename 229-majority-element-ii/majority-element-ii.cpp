class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0, count2=0;
        int ans1=INT_MIN, ans2=INT_MIN;
        vector<int> res;
        for (int i: nums){
            if (count1==0 && i!=ans2){
                ans1=i;
                count1=1;
            }
            else if (count2==0 && i!=ans1){
                ans2=i;
                count2=1;
            }

            else if (i==ans1) count1++;
            else if (i==ans2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1=count2=0;

        for (int i: nums){
            if (i==ans1) count1++;
            if (i==ans2) count2++;
        }
        int n = nums.size();
        if (count1>n/3) res.push_back(ans1);
        if (count2>n/3) res.push_back(ans2);
        return res;
    }
};