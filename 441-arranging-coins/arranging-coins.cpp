typedef long long ll;
class Solution {
public:
    int arrangeCoins(int n) {
        ll l = 0;
        ll r = n;

        while (l<=r){
            ll mid = l+ (r-l)/2;
            ll coins = mid*(mid+1)/2;
            if (coins<=n) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};