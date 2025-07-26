class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long N =n;
        if (N<0){
            N=-N;
            x=1/x;
        }

        while (N>0){
            if (N%2!=0){
                ans*=x;
            }

            x*=x;
            N/=2;
        }
        return ans;
    }
};