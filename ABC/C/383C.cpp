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
    ll H, W, D;
    cin >> H >> W >> D;

    vector<string> S(H);
    rep(i, H) { cin >> S[i]; }

    vvbool hum(H, vbool(W, false));

    queue<pair<ll, pll>> q;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'H') {
                q.push({D, {i, j}});
            }
        }
    }
    while (!q.empty()) {
        ll d = q.front().first;
        pll now = q.front().second;
        q.pop();
        hum[now.first][now.second] = true;
        if (d == 0) continue;
        rep(i, 4) {
            ll ny = now.first + dir[i].first;
            ll nx = now.second + dir[i].second;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#') continue;
            if (hum[ny][nx]) continue;
            hum[ny][nx] = true;
            q.push({d - 1, {ny, nx}});
        }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (hum[i][j] && S[i][j] != '#') {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
