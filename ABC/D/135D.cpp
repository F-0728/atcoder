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

using mint = modint1000000007;
// using mint = modint998244353;
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
    string S;
    cin >> S;

    ll N = S.size();
    vll mod13(N, 0);
    mod13[0] = 1;
    rep(i, N - 1) {
        mod13[i + 1] = mod13[i] * 10;
        mod13[i + 1] %= 13;
    }

    reverse(S.begin(), S.end());

    vvmint dp(N + 1, vmint(13, 0));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, 13) {
            if (S[i] == '?') {
                rep(k, 10) {
                    ll K = k * mod13[i];
                    dp[i + 1][(j + K) % 13] += dp[i][j];
                }
            } else {
                ll k = (S[i] - '0') * mod13[i];
                dp[i + 1][(j + k) % 13] += dp[i][j];
            }
        }
    }

    // rep(i, N + 1) {
    //     rep(j, 13) {
    //         cout << dp[i][j].val() << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][5].val() << endl;

    return 0;
}
