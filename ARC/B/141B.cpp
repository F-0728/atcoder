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
    ll N, M;
    cin >> N >> M;

    ll dig = 0;
    ll m = M;
    while (m > 0) {
        dig++;
        m /= 2;
    }
    if (N > dig) {
        cout << 0 << endl;
        return 0;
    }

    // i番目がj桁になる場合の数
    vvmint dp(N + 1, vmint(dig + 1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        for (ll j = 1; j < dig; j++) {
            rep(k, j) {
                dp[i + 1][j] += dp[i][k];
            }
            dp[i + 1][j] *= (1LL << (j - 1));
        }
        // 最終桁だけは確定してないから100...0だけ考えてあとでMまで足す
        rep(j, dig) {
            dp[i + 1][dig] += dp[i][j];
        }
    }

    // rep(i, N + 1) {
    //     rep(j, dig + 1) {
    //         cout << dp[i][j].val() << " ";
    //     }
    //     cout << endl;
    // }

    mint ans = 0;
    rep(i, dig) {
        ans += dp[N][i];
    }

    ll rem = M - (1LL << (dig - 1));
    ans += dp[N][dig] * (rem + 1);

    cout << ans.val() << endl;


    return 0;
}
