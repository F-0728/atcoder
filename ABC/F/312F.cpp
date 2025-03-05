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
    ll N, M;
    cin >> N >> M;
    vvll p(3);
    rep(i, N) {
        ll T, X;
        cin >> T >> X;
        p[T].push_back(X);
    }

    sort(p[0].rbegin(), p[0].rend());
    sort(p[1].rbegin(), p[1].rend());
    sort(p[2].rbegin(), p[2].rend());
    ll N0 = p[0].size();
    ll N1 = p[1].size();
    ll N2 = p[2].size();
    vll max0(N0 + 1, 0);
    vll max1(N1 + 1, 0);
    vll openmax(N2 + 1, 0);
    rep(i, N0) {
        max0[i + 1] = max0[i] + p[0][i];
    }
    rep(i, N1) {
        max1[i + 1] = max1[i] + p[1][i];
    }
    rep(i, N2) {
        openmax[i + 1] = openmax[i] + p[2][i];
    }

    vll dp(N1 + N2 + 1, 0);
    rep(i, N1) {
        ll need = lower_bound(openmax.begin(), openmax.end(), i + 1) - openmax.begin();
        if (need > N2) continue;
        dp[i + 1 + need] = max(dp[i + 1 + need], max1[i + 1]);
    }
    rep(i, N1 + N2) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    // outv(dp);

    ll ans = 0;
    rep(i, N0 + 1) {
        ll sum = max0[i];
        ll rem = M - i;
        if (rem < 0) continue;
        sum += dp[min(N1 + N2, rem)];
        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}
