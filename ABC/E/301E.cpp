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

vvll dist(ll si, ll sj, ll H, ll W, vector<string>& s) {
    vvll dist(H, vll(W, INF));
    dist[si][sj] = 0;
    queue<pll> q;
    q.push({si, sj});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (auto [dr, dc] : dir) {
            ll nr = r + dr;
            ll nc = c + dc;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (s[nr][nc] == '#') continue;
            if (dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}

int main() {
    ll H, W, T;
    cin >> H >> W >> T;
    vector<string> s(H);
    rep(i, H) {
        cin >> s[i];
    }

    pll start, goal;
    vpll c;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == 'S') {
                start = {i, j};
            } else if (s[i][j] == 'G') {
                goal = {i, j};
            } else if (s[i][j] == 'o') {
                c.push_back({i, j});
            }
        }
    }
    ll count = c.size();

    vvll distS = dist(start.first, start.second, H, W, s);
    vvll distG = dist(goal.first, goal.second, H, W, s);
    vector<vvll> distC(count, vvll(H, vll(W, INF)));
    rep(idx, count) {
        auto [i, j] = c[idx];
        vvll d = dist(i, j, H, W, s);
        rep(k, H) {
            rep(l, W) {
                distC[idx][k][l] = d[k][l];
            }
        }
    }

    ll ans = -1;
    if (distS[goal.first][goal.second] <= T) {
        ans = 0;
    }
    vvll dp(1 << count, vll(count, INF));
    rep(i, count) {
        dp[1 << i][i] = distS[c[i].first][c[i].second];
    }
    rep(i, 1 << count) {
        rep(j, count) {
            if (dp[i][j] == INF) continue;
            rep(k, count) {
                if (i >> k & 1) continue;
                dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + distC[j][c[k].first][c[k].second]);
            }
        }
    }

    // outvv(dp);

    rep(i, 1 << count) {
        if (i == 0) continue;
        rep(j, count) {
            if (dp[i][j] == INF) continue;
            ll d = dp[i][j] + distG[c[j].first][c[j].second];
            if (d <= T) {
                ans = max(ans, (ll)__builtin_popcount(i));
            }
        }
    }


    cout << ans << endl;

    return 0;
}
