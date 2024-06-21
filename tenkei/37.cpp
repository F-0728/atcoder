#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

ll op(ll a, ll b) { return max(a, b); }

ll e() { return -INF; }

int main() {
    ll W, N;
    cin >> W >> N;
    vll L(N), R(N), V(N);
    rep(i, N) cin >> L.at(i) >> R.at(i) >> V.at(i);
    ll pow = 1;
    while (pow < W + 1) pow *= 2;
    segtree<ll, op, e> seg(2 * pow);

    vvll dp(N + 1, vll(W + 1, -INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, W + 1) {
            seg.set(j + pow, dp.at(i).at(j));
        }
        rep(j, W + 1) {
            if (j < L.at(i)) {
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            } else {
                ll left = max(0LL, j - R.at(i));
                ll right = j - L.at(i) + 1;
                dp.at(i + 1).at(j) = max(dp.at(i).at(j), seg.prod(left + pow, right + pow) + V.at(i));
                // cout << seg.prod(left, right) << endl;
            }
        }
    }
    if (dp.at(N).at(W) < 0) {
        cout << -1 << endl;
    } else {
        cout << dp.at(N).at(W) << endl;
    }

    return 0;
}
