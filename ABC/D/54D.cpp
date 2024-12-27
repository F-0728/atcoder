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

int main() {
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vvll p(N, vll(3));
    rep(i, N) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }

    ll maxA = 0, maxB = 0;
    rep(i, N) {
        maxA += p[i][0];
        maxB += p[i][1];
    }

    vector<vvll> dp(N + 1, vvll(maxA + 1, vll(maxB + 1, INF)));
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, maxA + 1) {
            rep(k, maxB + 1) {
                if (j - p[i][0] >= 0 && k - p[i][1] >= 0) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - p[i][0]][k - p[i][1]] + p[i][2]);
                }
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    ll ans = INF;
    for (ll i = 1; i <= maxA; i++) {
        for (ll j = 1; j <= maxB; j++) {
            if (i * Mb == j * Ma) {
                ans = min(ans, dp[N][i][j]);
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
