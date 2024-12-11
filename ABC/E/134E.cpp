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

ll y;
bool f(ll x) { return x <= y; }

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) { cin >> A[i]; }

    segtree<ll, opmax, emax> seg(N);
    rep(i, N) { seg.set(i, A[i]); }

    vll color(N);
    rep(i, N) { color[i] = i; }

    ll ans = 0;
    rep(i, N) {
        if (seg.get(i) == -INF) continue;
        ans++;
        ll a = A[i];
        y = a;
        ll l = seg.max_right<f>(i);
        while (l != N) {
            color[l] = color[i];
            seg.set(l, -INF);
            y = A[l];
            l = seg.max_right<f>(l);
        }
    }

    cout << ans << endl;

    return 0;
}
