class Solution {
public:
    int hammingWeight(int n) {
        // Brian Kernigham Algo        
        int count=0;

        while (n>0){
            n = n&(n-1);
            count++;
        }
        return count;
    }
};