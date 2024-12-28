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
    ll N, M, K;
    cin >> N >> M >> K;
    vvbool ok(N, vbool(N, true));
    vpll edges(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[i] = {a, b};
        ok[a][b] = false;
        ok[b][a] = false;
    }

    vvmint dp(K + 1, vmint(N, 0));
    dp[0][0] = 1;
    rep(i, K) {
        mint sum = 0;
        rep(j, N) {
            sum += dp[i][j];
        }
        rep(j, N) {
            dp[i + 1][j] = sum - dp[i][j];
        }
        rep(j, M) {
            dp[i + 1][edges[j].first] -= dp[i][edges[j].second];
            dp[i + 1][edges[j].second] -= dp[i][edges[j].first];
        }
    }

    // outvvmint(dp);

    cout << dp[K][0].val() << endl;

    return 0;
}
