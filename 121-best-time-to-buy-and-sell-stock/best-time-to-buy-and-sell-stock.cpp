class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int mini = INT_MAX;
        int profit = 0;
        for (int i: prices){
            ans = max(i-mini, ans);
            mini = min(i, mini);
        }
        if (ans<0) return 0;
        return ans;
    }
};