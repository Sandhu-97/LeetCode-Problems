typedef long long ll;
class Solution {
public:
    ll count(int n){
        if (n<=0) return 0;
        if (n<10) return 1;

        ll base = 1;
        while (base*10 <= n) base*=10;

        ll msd = n/base;
        ll rest = n%base;

        ll ones_from_msd = 0;
        if (msd ==1){
            ones_from_msd = rest+1;
        }
        else{
            ones_from_msd = base;
        }

        return ones_from_msd + msd*count(base-1) + count(rest);
    }
    int countDigitOne(int n) {
        return (int)count(n);
    }
};