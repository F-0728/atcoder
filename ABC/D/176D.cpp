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
    ll H, W;
    cin >> H >> W;
    pll start, goal;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    start.first--; start.second--; goal.first--; goal.second--;

    vector<string> S(H);
    rep(i, H) {
        cin >> S[i];
    }

    vector<vector<ll>> dist(H, vector<ll>(W, INF));
    dist[start.first][start.second] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start.first * W + start.second});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        ll x = v / W;
        ll y = v % W;
        if (d > dist[x][y]) {
            continue;
        }
        dist[x][y] = d;
        rep(i, 4) {
            ll nx = x + dir[i].first;
            ll ny = y + dir[i].second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                continue;
            }
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                pq.push({dist[nx][ny], nx * W + ny});
            }
        }
        for (ll i = -2; i <= 2; i++) {
            for (ll j = -2; j <= 2; j++) {
                ll nx = x + i;
                ll ny = y + j;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    continue;
                }
                if (S[nx][ny] == '#') continue;
                if (dist[nx][ny] != INF) continue;
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    pq.push({dist[nx][ny], nx * W + ny});
                }
            }
        }
    }

    if (dist[goal.first][goal.second] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[goal.first][goal.second] << endl;
    }

    return 0;
}
