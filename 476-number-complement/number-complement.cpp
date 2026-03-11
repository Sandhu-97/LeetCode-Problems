class Solution {
public:
    int findComplement(int n) {
        int ans = 0;
        if (n==0) return 1;
        vector<int> bits;
        while (n){
            int bit = n&1;
            n>>=1;
            bits.push_back(!bit);
        }

        for (int i=bits.size()-1;i>=0;i--){
            ans <<=1;
            ans|=bits[i];
        }

        return ans;
    }
};