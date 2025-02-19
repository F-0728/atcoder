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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) { iota(idx.begin(), idx.end(), 0); sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; }); }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << "\n";}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << "\n";}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << "\n"; }}

const ll MAX = 2000005;
mint fact[MAX], factInv[MAX], inv[MAX];

void init() {
    ll MOD = mint::mod();
    fact[0] = fact[1] = 1;
    factInv[0] = factInv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        factInv[i] = factInv[i - 1] * inv[i];
    }
}

mint nPr(ll n, ll r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[n - r];
}

mint nCr(ll n, ll r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[r] * factInv[n - r];
}

int main() {
    ll K;
    cin >> K;
    vll C(26);
    rep(i, 26) {
        cin >> C[i];
    }

    init();

    vvmint dp(27, vmint(K + 1, 0));
    dp[0][0] = 1;
    rep(i, 26) {
        rep(j, K + 1) {
            rep(k, j + 1) {
                if (k > C[i]) continue;
                dp[i + 1][j] += dp[i][j - k] * nCr(j, k);
            }
        }
    }

    mint ans = 0;
    rep(i, K + 1) {
        if (i == 0) continue;
        ans += dp[26][i];
    }

    cout << ans.val() << endl;

    return 0;
}
