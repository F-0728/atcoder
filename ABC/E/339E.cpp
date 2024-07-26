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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return 0;
}

int main() {
    ll N, D;
    cin >> N >> D;
    ll nMax = 5e5;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    vll dp(nMax + 1, 0);
    dp.at(A.at(0)) = 1;
    segtree<ll, op, e> seg(dp);
    rep(i, N - 1) {
        ll a = A.at(i + 1);
        ll l = max(0LL, a - D);
        ll r = min(nMax, a + D);
        ll maxA = seg.prod(l, r + 1);
        seg.set(a, maxA + 1);
    }
    ll ans = seg.all_prod();
    cout << ans << endl;

    return 0;
}
