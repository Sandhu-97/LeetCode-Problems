class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while (n>0){
            int rem = n%2;
            if (rem) count++;
            n/=2;
        }
        return count;
    }
};