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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

ll op(ll x, ll y) { return x ^ y; }
ll e() { return 0; }

int main() {
    ll N, Q;
    cin >> N >> Q;
    ll p = 1;
    while (p < N) {
        p *= 2;
    }
    segtree<ll, op, e> seg(2 * p);
    rep(i, N) {
        ll a;
        cin >> a;
        seg.set(p + i, a);
    }
    rep(i, Q) {
        ll T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1) {
            seg.set(p + X - 1, seg.get(p + X - 1) ^ Y);
        } else {
            cout << seg.prod(p + X - 1, p + Y) << endl;
        }
    }

    return 0;
}
