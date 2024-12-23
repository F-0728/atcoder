#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << endl;}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << endl; }}

// first..max val & count, second..second max val & count
pair<pll, pll> op(pair<pll, pll> a, pair<pll, pll> b) {
    pair<pll, pll> res = {{0, 0}, {0, 0}};
    ll lMaxV = a.first.first;
    ll lMaxC = a.first.second;
    ll lSecV = a.second.first;
    ll lSecC = a.second.second;
    ll rMaxV = b.first.first;
    ll rMaxC = b.first.second;
    ll rSecV = b.second.first;
    ll rSecC = b.second.second;

    if (lMaxV > rMaxV) {
        res.first.first = lMaxV;
        res.first.second = lMaxC;
        if (lSecV > rMaxV) {
            res.second.first = lSecV;
            res.second.second = lSecC;
        } else if (lSecV < rMaxV) {
            res.second.first = rMaxV;
            res.second.second = rMaxC;
        } else {
            res.second.first = lSecV;
            res.second.second = lSecC + rMaxC;
        }
    } else if (lMaxV < rMaxV) {
        res.first.first = rMaxV;
        res.first.second = rMaxC;
        if (rSecV > lMaxV) {
            res.second.first = rSecV;
            res.second.second = rSecC;
        } else if (rSecV < lMaxV) {
            res.second.first = lMaxV;
            res.second.second = lMaxC;
        } else {
            res.second.first = rSecV;
            res.second.second = rSecC + lMaxC;
        }
    } else {
        res.first.first = lMaxV;
        res.first.second = lMaxC + rMaxC;
        if (lSecV > rSecV) {
            res.second.first = lSecV;
            res.second.second = lSecC;
        } else if (lSecV < rSecV) {
            res.second.first = rSecV;
            res.second.second = rSecC;
        } else {
            res.second.first = lSecV;
            res.second.second = lSecC + rSecC;
        }
    }

    return res;
}

pair<pll, pll> e() {
    return {{0, 0}, {0, 0}};
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) cin >> A[i];

    segtree<pair<pll, pll>, op, e> seg(N);
    rep(i, N) {
        seg.set(i, {{A[i], 1}, {0, 0} });
    }

    rep(i, Q) {
        ll T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1) {
            X--;
            seg.set(X, {{Y, 1}, {0, 0}});
        } else {
            X--;
            cout << seg.prod(X, Y).second.second << endl;
        }
    }



    return 0;
}
