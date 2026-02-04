class Solution {
public:
    int solve(int n){
        if (n==1) return 0;
        if (n<=3) return n;

        for (int i=2;i<=n/2;i++){
            if (n%i==0) return i+solve(n/i);
        }
        return n;
    }
    int minSteps(int n) {
        return solve(n);
    }
};