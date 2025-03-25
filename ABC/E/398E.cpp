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
    ll N;
    cin >> N;
    vvbool connected(N, vbool(N, false));
    vvll G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
        connected.at(a).at(b) = true;
        connected.at(b).at(a) = true;
    }

    vbool color(N, false);
    color.at(0) = true;
    queue<pll> q;
    q.push({0, -1});
    while (!q.empty()) {
        auto [v, p] = q.front();
        q.pop();
        for (auto nv : G.at(v)) {
            if (nv == p) continue;
            color.at(nv) = !color.at(v);
            q.push({nv, v});
        }
    }

    set<pll> ok;
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            if (connected.at(i).at(j)) continue;
            if (color.at(i) == color.at(j)) continue;
            ok.insert({i, j});
        }
    }

    if (ok.size() & 1) {
        cout << "First" << "\n";
        pll p = *ok.begin();
        cout << p.first + 1 << " " << p.second + 1 << endl;
        ok.erase(p);
    } else {
        cout << "Second" << endl;
    }

    while (true) {
        ll u, v;
        cin >> u >> v;
        if (u == -1 || v == -1) break;
        u--; v--;
        if (u > v) swap(u, v);
        ok.erase({u, v});
        pll p = *ok.begin();
        cout << p.first + 1 << " " << p.second + 1 << endl;
        ok.erase(p);
    }

    return 0;
}
