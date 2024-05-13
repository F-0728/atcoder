#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll MOD = 1000000000 + 7;

int main() {
    ll n, l;
    cin >> n >> l;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++) {
        if (i<l) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1] + dp[i-l]) % MOD;
    }
    cout << dp[n] << endl;

    return 0;
}
