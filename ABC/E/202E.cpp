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

vll depth, in, out;

void dfs(ll v, ll p, ll d, ll i, vvll& G) {
    depth.at(v) = d;
    in.at(v) = i;
    ll now = i;
    for (ll nv : G.at(v)) {
        if (nv == p) {
            continue;
        }
        dfs(nv, v, d + 1, now + 1, G);
        now = max(now, out.at(nv));
    }
    out.at(v) = now + 1;
}

int main() {
    ll N;
    cin >> N;
    vvll G(N);
    for (ll i = 1; i <= N - 1; i++) {
        ll a;
        cin >> a;
        G.at(a - 1).push_back(i);
        G.at(i).push_back(a - 1);
    }

    depth.assign(N, -1);
    in.assign(N, -1);
    out.assign(N, -1);

    dfs(0, -1, 0, 0, G);

    // outv(depth);
    // outv(in);
    // outv(out);

    vvll v(N);
    rep(i, N) {
        v.at(depth.at(i)).push_back(in.at(i));
    }
    rep(i, N) {
        sort(v.at(i).begin(), v.at(i).end());
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll U, D;
        cin >> U >> D;
        U--;
        ll lb = lower_bound(v.at(D).begin(), v.at(D).end(), in.at(U)) - v.at(D).begin();
        ll ub = upper_bound(v.at(D).begin(), v.at(D).end(), out.at(U)) - v.at(D).begin();
        cout << ub - lb << endl;
    }

    return 0;
}
