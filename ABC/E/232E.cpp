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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) { iota(idx.begin(), idx.end(), 0); sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; }); }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << "\n";}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << "\n";}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << "\n"; }}

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    mint h = H;
    mint w = W;

    // i...x1とx2が同じ場合 j...y1とy2が同じ場合
    vvmint dp(2, vmint(2, 0));
    dp[x1 != x2][y1 != y2] = 1;
    while (K--) {
        vvmint ndp(2, vmint(2, 0));
        ndp[0][0] = dp[0][1] + dp[1][0];
        ndp[0][1] = dp[0][0] * (w - 1) + dp[0][1] * (w - 2) + dp[1][1];
        ndp[1][0] = dp[0][0] * (h - 1) + dp[1][0] * (h - 2) + dp[1][1];
        ndp[1][1] = dp[0][1] * (h - 1) + dp[1][0] * (w - 1) + dp[1][1] * (h - 2) + dp[1][1] * (w - 2);
        dp = ndp;
    }

    cout << dp[0][0].val() << endl;

    return 0;
}
