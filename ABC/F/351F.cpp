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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    vpll order(N);
    rep(i, N) { order[i] = {A[i], i}; }
    sort(order.rbegin(), order.rend());

    ll ans = 0;
    segtree<ll, op, e> sumseg(N);
    segtree<ll, op, e> count(N);
    rep(i, N) {
        ll idx = order[i].second;
        ll val = order[i].first;
        sumseg.set(idx, val);
        count.set(idx, 1);
        ans += sumseg.prod(idx + 1, N) - val * count.prod(idx + 1, N);
    }

    cout << ans << endl;

    return 0;
}
