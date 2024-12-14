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
    ll H, W, X;
    cin >> H >> W >> X;

    ll P, Q;
    cin >> P >> Q;
    P--; Q--;

    vvll S(H, vll(W));
    rep(i, H) {
        rep(j, W) {
            ll s;
            cin >> s;
            S[i][j] = s;
        }
    }
    vvbool used(H, vbool(W, false));
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    ll ans = S[P][Q];
    used[P][Q] = true;
    rep(i, 4) {
        ll nx = P + dir[i].first;
        ll ny = Q + dir[i].second;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        pq.push({S[nx][ny], {nx, ny}});
    }
    while (!pq.empty()) {
        auto [s, p] = pq.top();
        pq.pop();
        // cout << s << " " << p.first << " " << p.second << endl;
        if (used[p.first][p.second]) continue;
        ll x = p.first;
        ll y = p.second;
        bool ok = false;
        if (ans % X == 0) {
            if (s < ans / X) {
                ok = true;
                ans += s;
            }
        } else {
            if (s <= ans / X) {
                ok = true;
                ans += s;
            }
        }
        used[x][y] = true;
        if (!ok) continue;
        rep(i, 4) {
            ll nx = x + dir[i].first;
            ll ny = y + dir[i].second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (used[nx][ny]) continue;
            pq.push({S[nx][ny], {nx, ny}});
        }
    }

    cout << ans << endl;

    return 0;
}
