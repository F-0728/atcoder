#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll K;
    cin >> K;
    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<mint> dp(K + 1, 0);
    dp[0] = 0;
    for (ll i = 1; i <= 9; i++) {
        dp[i] = 1;
    }
    for (ll i = 2; i <= K; i++) {
        for (ll j = 1; j <= 9; j++) {
            if (i - j < 0) {
                break;
            }
            dp[i] += dp[i - j];
        }
    }
    cout << dp[K].val() << endl;

    return 0;
}
