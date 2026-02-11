class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        int target = sum/2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int w: stones){
            for (int x = target;x>=w;x--){
                dp[x] = dp[x] || dp[x-w];
            }
        }
        int ans = 0;
        for (int x = target;x>=0;x--){
            if (dp[x]){
                ans=x;
                break;
            }
        }
        return sum-2*ans;

    }
};