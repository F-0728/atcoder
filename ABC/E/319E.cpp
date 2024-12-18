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
    ll X, Y;
    cin >> X >> Y;
    vpll bus(N - 1);
    rep(i, N - 1) {
        ll P, T;
        cin >> P >> T;
        bus[i] = {P, T};
    }
    
    // ここは840
    ll LCM = 1;
    rep(i, 9) {
        if (i == 0) continue;
        LCM = lcm(LCM, i);
    }

    vll dp(840, INF);
    rep(i, 840) {
        ll start = i;
        start += X;
        rep(j, N - 1) {
            ll P = bus[j].first;
            ll T = bus[j].second;
            start = ((start - 1) / P + 1) * P + T;
        }
        start += Y;
        dp[i] = start;
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll q;
        cin >> q;
        ll ans = dp[q % 840];
        ans += q / 840 * 840;
        cout << ans << endl;
    }


    return 0;
}
