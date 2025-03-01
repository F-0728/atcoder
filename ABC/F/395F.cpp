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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
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
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) {
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; });
}
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << "\n";
}
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << "\n";
}
template <typename T>
void outvv(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        outv(v);
    }
}
void outvvmint(const vector<vector<mint>>& vv) {
    for (const auto& v : vv) {
        outvmint(v);
    }
}
template <typename T>
void outvp(const vector<pair<T, T>>& vp) {
    for (const auto& p : vp) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ll N, X;
    cin >> N >> X;
    vpll teeth(N);
    rep(i, N) {
        ll u, d;
        cin >> u >> d;
        teeth[i] = {u, d};
    }
    ll m = INF;
    rep(i, N) { m = min(m, teeth[i].first + teeth[i].second); }

    ll l = 0, r = m + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        bool ok = true;
        ll u = teeth[0].first, d = teeth[0].second;
        ll L = max(0LL, mid - d), R = min(u, mid);
        if (L > R) {
            ok = false;
        }
        for (ll i = 1; i < N; i++) {
            ll nu = teeth[i].first, nd = teeth[i].second;
            ll NL = max(L - X, max(0LL, mid - nd)), NR = min(R + X, nu);
            if (NL > NR) {
                ok = false;
                break;
            }
            L = NL;
            R = NR;
            u = nu;
            d = nd;
        }
        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // cout << l << "\n";

    ll ans = 0;
    rep(i, N) {
        ans += teeth[i].first;
        ans += teeth[i].second;
    }
    ans -= l * N;
    cout << ans << "\n";

    return 0;
}
