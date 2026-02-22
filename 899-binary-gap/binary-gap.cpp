class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int dist = 0;
        bool seen = false;
        while (n){
            int bit = n&1;
            n>>=1;

            if (bit==1){
                if (seen) ans = max(ans, dist);
                seen=true;
                dist=1;
            }
            else if (seen) dist++;
        
        }
        return ans;
    }
};