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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll op(ll a, ll b) {
    return min(a, b);
}
ll e() {
    return INF;
}

int main() {
    ll N, L, K;
    cin >> N >> L >> K;

    vll loc(N);
    vll price(N);
    rep(i, N) {
        ll A, C;
        cin >> A >> C;
        loc[i] = A;
        price[i] = C;
    }

    segtree<ll, op, e> seg(N);
    rep(i, N) {
        seg.set(i, price[i]);
    }

    ll ans = 0;
    rep(i, L - K) {
        ll l = lower_bound(loc.begin(), loc.end(), i + 1) - loc.begin();
        ll r = upper_bound(loc.begin(), loc.end(), i + K) - loc.begin();
        if (l == r) {
            cout << -1 << endl;
            return 0;
        }
        ans += seg.prod(l, r);
    }

    cout << ans << endl;


    return 0;
}
