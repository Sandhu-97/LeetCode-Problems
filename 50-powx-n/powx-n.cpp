class Solution {
public:

    double solve(double x, int e, double ans){
        if (e==0) return ans;
        if (e%2==0){
            return solve(x*x, e/2, ans);
        }
        else return solve(x*x, e/2, ans*x);

    }
    double myPow(double x, int n) {
        if (n==0) return 1.0;
        long int e = n;
        if (e<0) e=-e;
        double ans = solve(x, e, ans);
        if (n>0) return ans;
        return 1.0/ans;
    }
};