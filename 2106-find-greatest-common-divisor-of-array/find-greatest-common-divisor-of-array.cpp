class Solution {
public:
    int gcd(int a, int b){
        if (b==0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int min=nums[0], max = nums[0];
        for (int i: nums){
            if (i< min) min = i;
            if (i>max) max=i;
        }

        return gcd(max, min);
    }
};