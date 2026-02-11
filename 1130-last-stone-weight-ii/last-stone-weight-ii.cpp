class Solution {
public:
    int n, sum;
    vector<vector<int>> dp;

    int solve(int i, int diff, vector<int>& stones){
        if (i==n) return abs(diff);

        int key = diff+sum;
        if(dp[i][key]!=-1) return dp[i][key];

        int set1 = solve(i+1, diff+stones[i], stones);
        int set2 = solve(i+1, diff-stones[i], stones);

        return dp[i][key] = min(set1, set2);
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        sum = accumulate(stones.begin(), stones.end(), 0);
        dp.assign(n, vector<int> (2*sum+1, -1));

        return solve(0, 0, stones);
    }
};