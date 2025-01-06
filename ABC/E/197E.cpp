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
    ll N;
    cin >> N;
    vvll balls(N);
    rep(i, N) {
        ll X, C;
        cin >> X >> C;
        C--;
        balls[C].push_back(X);
    }

    rep(i, N) {
        sort(balls[i].begin(), balls[i].end());
    }

    vvll dp(N + 1, vll(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    ll prevl = 0, prevr = 0;
    rep(i, N) {
        if (balls[i].size() == 0) {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            continue;
        }
        ll l = balls[i].front();
        ll r = balls[i].back();
        dp[i + 1][0] = min(dp[i][0] + abs(prevr - l) + r - l, dp[i][1] + abs(prevl - l) + r - l);
        dp[i + 1][1] = min(dp[i][0] + abs(prevr - r) + r - l, dp[i][1] + abs(prevl - r) + r - l);
        prevl = l;
        prevr = r;
    }

    ll ans = min(dp[N][0] + abs(prevr), dp[N][1] + abs(prevl));

    cout << ans << endl;

    return 0;
}
