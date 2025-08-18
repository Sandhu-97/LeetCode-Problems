class Solution {
public:

    int solve (int i, int prev, vector<vector<int>>& nums, vector<vector<int>>& dp){
        if (i>= nums.size()) return 0;

        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

        int take=0;
        if (prev==-1 || nums[i][0] > nums[prev][1]) take = 1 + solve(i+1, i, nums, dp);
        int skip = solve(i+1, prev, nums, dp);

        if (prev!=-1) {
            dp[i][prev] = max(take, skip);
        }
        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        for (auto i: pairs) cout << i[0] << " " << i[1] << endl;
        
        int n = pairs.size();

        vector<vector<int>> dp (n+1 ,vector<int>(n+1, -1));

        return solve(0, -1, pairs, dp);
    }
};