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

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll N, M;
        cin >> N >> M;
        vll C(N);
        rep(j, N) {
            cin >> C[j];
        }
        vvll G(N);
        rep(i, M) {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vvll newG(N * N);
        rep(i, N) {
            rep(j, N) {
                if (C[i] == C[j]) continue;
                for (auto& v : G[i]) {
                    for (auto& u : G[j]) {
                        if (C[v] != C[u]) {
                            newG[i * N + j].push_back(v * N + u);
                        }
                    }
                }
            }
        }
        queue<pll> q;
        q.push({0, N - 1});
        vll dist(N * N, INF);
        dist[0] = 0;

        bool ok = false;
        while (!q.empty()) {
            auto [d, v] = q.front();
            q.pop();
            if (dist[v] < d) continue;
            if (v == N * (N - 1)) {
                cout << d << endl;
                ok = true;
                break;
            }
            for (auto& u : newG[v]) {
                if (dist[u] > d + 1) {
                    dist[u] = d + 1;
                    q.push({d + 1, u});
                }
            }
        }
        if (!ok) {
            cout << -1 << endl;
        }
    }

    return 0;
}
