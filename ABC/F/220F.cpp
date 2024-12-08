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

vll ans;
vll Size;
vvll G;
void dfs(ll v, ll p) {
    ll res = 1;
    for (auto nv : G.at(v)) {
        if (nv == p) continue;
        dfs(nv, v);
        res += Size.at(nv);
    }
    Size.at(v) = res;
}

int main() {
    ll N;
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    Size.resize(N, 0);
    ans.resize(N, -1);
    ans.at(0) = 0;
    dfs(0, -1);
    vbool visited(N, false);
    queue<pll> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [d, v] = q.front();
        q.pop();
        if (visited.at(v)) continue;
        ans.at(0) += d;
        visited.at(v) = true;
        for (auto nv : G.at(v)) {
            if (visited.at(nv)) continue;
            q.push({d + 1, nv});
        }
    }

    q.push({0, -1});
    while (!q.empty()) {
        auto [v, p] = q.front();
        q.pop();
        for (auto nv : G.at(v)) {
            if (nv == p) continue;
            ans.at(nv) = ans.at(v) + N - 2 * Size.at(nv);
            q.push({nv, v});
        }
    }

    rep(i, N) {
        cout << ans.at(i) << endl;
    }


    return 0;
}
