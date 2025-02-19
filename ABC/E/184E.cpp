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
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) {
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) {
        if (v[i1] == v[i2]) {
            return i1 < i2;
        }
        return v[i1] < v[i2];
    });
}
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << endl;
}
template <typename T>
void outvv(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        outv(v);
    }
}
void outvvmint(const vector<vector<mint>>& vv) {
    for (const auto& v : vv) {
        outvmint(v);
    }
}
template <typename T>
void outvp(const vector<pair<T, T>>& vp) {
    for (const auto& p : vp) {
        cout << p.first << " " << p.second << endl;
    }
}


int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    vector<vpll> tel(26);
    rep(i, H) {
        cin >> s[i];
    }
    pll start, goal;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '#') continue;
            if (s[i][j] == 'S') {
                start = {i, j};
            }
            if (s[i][j] == 'G') {
                goal = {i, j};
            }
            if (s[i][j] >= 'a' && s[i][j] <= 'z') {
                tel[s[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    vvll dist(H, vll(W, INF));
    dist[start.first][start.second] = 0;

    queue<pll> q;
    q.push(start);
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 4) {
            ll nr = r + dir[i].first;
            ll nc = c + dir[i].second;
            if (nr < 0 || nc < 0 || nr >= H || nc >= W) {
                continue;
            }
            if (s[nr][nc] == '#') {
                continue;
            }
            if (dist[nr][nc] <= dist[r][c] + 1) {
                continue;
            }
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
        if (s[r][c] != '.' && s[r][c] != 'S' && s[r][c] != 'G') {
            if (tel[s[r][c] - 'a'].empty()) continue;
            for (auto [nr, nc] : tel[s[r][c] - 'a']) {
                if (dist[nr][nc] <= dist[r][c] + 1) {
                    continue;
                }
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
            tel[s[r][c] - 'a'].clear();
        }
    }

    // outvv(dist);

    if (dist[goal.first][goal.second] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[goal.first][goal.second] << endl;
    }


    return 0;
}
