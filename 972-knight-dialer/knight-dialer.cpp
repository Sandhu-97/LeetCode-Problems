class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9+7;
        vector<vector<int>> moves = {
            {4, 6},
            {6, 8}, 
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        vector<long long> prev(10, 1), curr(10, 0);

        for (int step=2;step<=n ;step++){
            fill(curr.begin(), curr.end(), 0);

            for (int d = 0; d< 10; d++){
                for (int nxt: moves[d]){
                    curr[nxt] = (curr[nxt]+prev[d]) % mod;
                }
            }
            prev = curr;
        }
        long long ans = 0;
        for (long long i: prev){
            ans = (ans+i) % mod;
        }
        return ans;
    }
};