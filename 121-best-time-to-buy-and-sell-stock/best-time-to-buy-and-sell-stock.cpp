class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for (int i: prices){
            ans = max(i-mini, ans);
            mini = min(i, mini);
        }
        return ans;
    }
};