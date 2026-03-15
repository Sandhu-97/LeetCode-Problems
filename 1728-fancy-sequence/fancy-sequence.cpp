class Fancy {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;

    vector<ll> arr;
    ll mul = 1;
    ll add = 0;

    ll modPow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    ll modInverse(ll x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        ll x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};