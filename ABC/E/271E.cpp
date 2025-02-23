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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vpll> G(N);
    vvll edges(M);
    rep(i, M) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        edges[i] = {A, B, C};
        G[A].push_back({B, C});
    }

    vll E(K);
    rep(i, K) {
        cin >> E[i];
        E[i]--;
    }

    vll dist(N, INF);
    dist[0] = 0;
    rep(i, K) {
        ll A = edges[E[i]][0];
        ll B = edges[E[i]][1];
        ll C = edges[E[i]][2];
        if (dist[A] == INF) continue;
        dist[B] = min(dist[B], dist[A] + C);
    }
    

    if (dist[N - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[N - 1] << endl;
    }


    return 0;
}
