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
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vll p(80), t(80);

ll patty(ll N, ll X) {
    if (N == 0) return 1;
    if (X <= 1) return 0;
    if (X <= t[N - 1] + 1) {
        return patty(N - 1, X - 1);
    }
    if (X == t[N - 1] + 2) {
        return p[N - 1] + 1;
    }
    if (X <= 2 * t[N - 1] + 2) {
        return p[N - 1] + 1 + patty(N - 1, X - t[N - 1] - 2);
    }
    return 2 * p[N - 1] + 1;
}

int main() {
    ll N, X;
    cin >> N >> X;
    p[0] = 1;
    t[0] = 1;
    rep(i, N) {
        p[i + 1] = 2 * p[i] + 1;
        t[i + 1] = 2 * t[i] + 3;
    }
    // rep(i, N + 1) {
    //     cout << p[i] << " " << t[i] << endl;
    // }
    cout << patty(N, X) << endl;
    return 0;
}
