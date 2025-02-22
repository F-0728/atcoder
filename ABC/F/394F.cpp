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

vll dp;
vll deg;
ll ans = 0;
ll dfs(ll v, ll p, vvll& G) {
    if (dp[v] != -1) return dp[v];
    if (deg[v] == 1 && p != -1) return dp[v] = 1;
    vll res;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        res.push_back(dfs(nv, v, G));
    }
    sort(res.rbegin(), res.rend());
    if (res.size() >= 4) {
        ans = max(ans, res[0] + res[1] + res[2] + res[3] + 1);
    }
    if (res.size() >= 3) {
        dp[v] = res[0] + res[1] + res[2] + 1;
        if (p != -1) {
            ans = max(ans, dp[v] + 1);
        }
        return dp[v];
    } else {
        return dp[v] = 1;
    }
}

int main() {
    ll N;
    cin >> N;
    vvll G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dp = vll(N, -1);
    deg = vll(N, 0);
    rep(i, N) {
        deg[i] = G[i].size();
    }

    dfs(0, -1, G);

    if (ans >= 5) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
