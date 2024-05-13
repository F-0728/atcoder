#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll MOD = 1000000007;

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 1;
    if (N == 1) {
        cout << K << endl;
        return 0;
    }
    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }
    ans *= K;
    ans %= MOD;
    ans *= (K - 1);
    ans %= MOD;
    ans *= power(K - 2 , N - 2);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}
