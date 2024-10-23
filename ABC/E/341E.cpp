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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
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

ll op(ll a, ll b) { return a + b; }

ll e() { return 0; }

int main() {
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    if (N == 1) {
        rep(i, Q) {
            ll T, L, R;
            cin >> T >> L >> R;
            if (T == 2) {
                Yes;
            }
        }
        return 0;
    }

    segtree<ll, op, e> sumseg(N - 1);
    rep(i, N - 1) { sumseg.set(i, S.at(i) == S.at(i + 1)); }

    rep(i, Q) {
        ll T, L, R;
        cin >> T >> L >> R;
        L--;
        R--;
        if (T == 1) {
            if (L != 0) {
                sumseg.set(L - 1, 1 - sumseg.get(L - 1));
            }
            if (R != N - 1) {
                sumseg.set(R, 1 - sumseg.get(R));
            }
        } else {
            if (sumseg.prod(L, R) == 0) {
                Yes;
            } else {
                No;
            }
        }
    }

    return 0;
}
