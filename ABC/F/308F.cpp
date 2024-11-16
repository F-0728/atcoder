#include <atcoder/all>
#include <bitset>
#include <chrono>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vll P(N);
    rep(i, N) cin >> P[i];
    vpll coupons(M);
    rep(i, M) {
        ll L;
        cin >> L;
        coupons[i].second = L;
    }
    rep(i, M) {
        ll D;
        cin >> D;
        coupons[i].first = D;
    }
    sort(coupons.rbegin(), coupons.rend());

    ll ans = 0;
    rep(i, N) { ans += P[i]; }
    multiset<ll> unused;
    rep(i, N) { unused.insert(P[i]); }
    rep(i, M) {
        ll D = coupons[i].first;
        ll L = coupons[i].second;
        auto it = unused.lower_bound(L);
        if (it == unused.end()) {
            continue;
        }
        ans -= D;
        unused.erase(unused.find(*it));
    }

    cout << ans << endl;

    return 0;
}
