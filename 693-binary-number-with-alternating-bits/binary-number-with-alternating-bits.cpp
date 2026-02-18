class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool one = true;
        int expected = n&1;
        while (n){
            int bit = n&1;
            if (bit!=expected) return false;
            expected = 1 - bit;
            n>>=1;
        }
        return true;
    }
};