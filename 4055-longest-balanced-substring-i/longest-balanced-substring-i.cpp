class Solution {
public:

    bool check(vector<int>& freq){
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i: freq){
            if (i==0) continue;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return maxi==mini;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i=0;i<n;i++){
            vector<int> freq(26, 0);
            for (int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if (check(freq)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};