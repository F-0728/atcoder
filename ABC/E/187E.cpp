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

int main() {
    ll N;
    cin >> N;
    vvll G(N);
    vpll edges(N - 1);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
        edges.at(i) = {a, b};
    }
    vll dp(N, 0);
    vll depth(N, -1);
    depth.at(0) = 0;

    auto dfs = [&](auto dfs, ll v, ll p, ll d) -> void {
        depth.at(v) = d;
        for (auto nv : G.at(v)) {
            if (nv == p) continue;
            dfs(dfs, nv, v, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        ll a = edges.at(e).first;
        ll b = edges.at(e).second;
        if (t == 1) {
            if (depth.at(a) < depth.at(b)) {
                dp.at(0) += x;
                dp.at(b) -= x;
            } else {
                dp.at(a) += x;
            }
        } else {
            if (depth.at(a) < depth.at(b)) {
                dp.at(b) += x;
            } else {
                dp.at(0) += x;
                dp.at(a) -= x;
            }
        }
    }

    auto dfs2 = [&](auto dfs2, ll v, ll p) -> void {
        for (auto nv : G.at(v)) {
            if (nv == p) continue;
            dp.at(nv) += dp.at(v);
            dfs2(dfs2, nv, v);
        }
    };

    dfs2(dfs2, 0, -1);

    rep(i, N) {
        cout << dp.at(i) << endl;
    }


    return 0;
}
