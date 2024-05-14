#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N);
    rep(i, N) cin >> x[i];
    if (x[0] > 0) {
        cout << x[K-1] << endl;
        return 0;
    }
    if (x[N-1] < 0) {
        cout << -x[N-K] << endl;
        return 0;
    }
    ll ans = 3e8;
    rep(i, N-K+1) {
        ans = min(ans, abs(x[i])*2 + abs(x[i+K-1]));
        ans = min(ans, abs(x[i]) + abs(x[i+K-1])*2);
    }
    cout << ans << endl;

    return 0;
}
