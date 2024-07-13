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
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vvll c(10, vector<ll>(10));

void warshall_floyd(ll n) {
    rep(k, n) {
        rep(i, n) {
            rep(j, n) { c[i][j] = min(c[i][j], c[i][k] + c[k][j]); }
        }
    }
}

int main() {
    ll H, W;
    cin >> H >> W;
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    warshall_floyd(10);

    ll ans = 0;
    vvll a(H, vll(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) {
        rep(j, W) {
            if (a[i][j] == -1) continue;
            ans += c[a[i][j]][1];
        }
    }
    cout << ans << endl;

    return 0;
}
