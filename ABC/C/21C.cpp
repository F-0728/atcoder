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

using mint = modint1000000007;
// using mint = modint998244353;
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

int main() {
    ll N;
    cin >> N;
    ll a, b;
    cin >> a >> b;
    a--; b--;
    ll M;
    cin >> M;

    vvll G(N);
    vvbool connected(N, vbool(N, false));
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
        connected[x][y] = true;
        connected[y][x] = true;
    }

    vll dist(N, INF);
    queue<pll> q;
    q.push({0, a});
    while (!q.empty()) {
        auto [d, v] = q.front();
        q.pop();
        if (dist[v] != INF) continue;
        dist[v] = d;
        for (auto nv : G[v]) {
            if (dist[nv] == INF) {
                q.push({d + 1, nv});
            }
        }
    }

    vvll newG(N);
    rep(i, N) {
        rep(j, N) {
            if (!connected[i][j]) continue;
            if (dist[i] + 1 == dist[j]) {
                newG[i].push_back(j);
            }
        }
    }

    vmint dp(N, 0);
    dp[a] = 1;
    queue<ll> q2;
    q2.push(a);
    while (!q2.empty()) {
        ll v = q2.front();
        q2.pop();
        for (auto nv : newG[v]) {
            if (dp[nv] == 0) {
                dp[nv] = dp[v];
                q2.push(nv);
            } else {
                dp[nv] += dp[v];
            }
        }
    }

    cout << dp[b].val() << endl;


    return 0;
}
