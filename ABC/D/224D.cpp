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
    ll M;
    cin >> M;
    vvll G(9);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vll p(8);
    rep(i, 8) {
        ll a;
        cin >> a;
        p[i] = a - 1;
    }

    vll idx(9, 0);
    rep(i, 8) {
        idx[p[i]] = i + 1;
    }

    map<vll, ll> dist;
    queue<vll> q;
    q.push(idx);
    dist[idx] = 0;
    while (!q.empty()) {
        vll v = q.front();
        q.pop();
        ll d = dist[v];
        ll zero = 0;
        rep(i, 9) {
            if (v[i] == 0) {
                zero = i;
                break;
            }
        }
        for (ll nv : G[zero]) {
            vll nvv = v;
            swap(nvv[zero], nvv[nv]);
            if (dist.find(nvv) == dist.end()) {
                dist[nvv] = d + 1;
                q.push(nvv);
            }
        }
    }

    vll goal(9);
    rep(i, 8) {
        goal[i] = i + 1;
    }

    if (dist.find(goal) == dist.end()) {
        cout << -1 << endl;
    } else {
        cout << dist[goal] << endl;
    }

    return 0;
}
