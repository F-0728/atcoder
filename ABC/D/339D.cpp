
#include <atcoder/all>
#include <bitset>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
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
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) { cin >> S[i]; }

    vvll G(N * N * N * N);
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                rep(l, N) {
                    pll p1 = {i, j};
                    pll p2 = {k, l};
                    if (S[i][j] == '#' || S[k][l] == '#') continue;
                    for (auto d : dir) {
                        ll x1 = p1.first + d.first;
                        ll y1 = p1.second + d.second;
                        ll x2 = p2.first + d.first;
                        ll y2 = p2.second + d.second;
                        if (x1 < 0) x1 = 0;
                        if (y1 < 0) y1 = 0;
                        if (x2 < 0) x2 = 0;
                        if (y2 < 0) y2 = 0;
                        if (x1 >= N) x1 = N - 1;
                        if (y1 >= N) y1 = N - 1;
                        if (x2 >= N) x2 = N - 1;
                        if (y2 >= N) y2 = N - 1;
                        if (S[x1][y1] == '#') x1 = i, y1 = j;
                        if (S[x2][y2] == '#') x2 = k, y2 = l;
                        if (x1 == i && y1 == j && x2 == k && y2 == l) continue;
                        G[i * N * N * N + j * N * N + k * N + l].push_back(x1 * N * N * N + y1 * N * N + x2 * N + y2);
                    }
                }
            }
        }
    }

    vll dist(N * N * N * N, INF);
    pll start1 = {-1, -1}, start2 = {-1, -1};
    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == 'P') {
                if (start1.first == -1) {
                    start1 = {i, j};
                } else {
                    start2 = {i, j};
                }
            }
        }
    }
    queue<ll> q;
    q.push(start1.first * N * N * N + start1.second * N * N + start2.first * N + start2.second);
    dist[start1.first * N * N * N + start1.second * N * N + start2.first * N + start2.second] = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (auto u : G[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    ll ans = INF;
    rep(i, N) {
        rep(j, N) {
            ans = min(ans, dist[i * N * N * N + j * N * N + i * N + j]);
        }
    }
    
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
