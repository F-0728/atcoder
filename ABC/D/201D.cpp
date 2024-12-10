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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) {
        cin >> S[i];
    }

    vvll dp(H, vll(W, 0));
    for (ll i = H - 1; i >= 0; i--) {
        for (ll j = W - 1; j >= 0; j--) {
            if (i == H - 1) {
                if (j == W - 1) {
                    if (S[i][j] == '+') {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = -1;
                    }
                } else {
                    dp[i][j] -= dp[i][j + 1];
                    if (S[i][j] == '+') {
                        dp[i][j]++;
                    } else {
                        dp[i][j]--;
                    }
                }
            } else {
                if (j == W - 1) {
                    dp[i][j] -= dp[i + 1][j];
                    if (S[i][j] == '+') {
                        dp[i][j]++;
                    } else {
                        dp[i][j]--;
                    }
                } else {
                    dp[i][j] -= max(dp[i + 1][j], dp[i][j + 1]);
                    if (S[i][j] == '+') {
                        dp[i][j]++;
                    } else {
                        dp[i][j]--;
                    }
                }
            }
        }
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (H == 1 && W == 1) {
        cout << "Draw" << endl;
    } else if (H == 1) {
        if (dp[0][1] > 0) {
            cout << "Takahashi" << endl;
        } else if (dp[0][1] < 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }
    } else if (W == 1) {
        if (dp[1][0] > 0) {
            cout << "Takahashi" << endl;
        } else if (dp[1][0] < 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }
    } else {
        if (max(dp[1][0], dp[0][1]) > 0) {
            cout << "Takahashi" << endl;
        } else if (max(dp[1][0], dp[0][1]) < 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

    return 0;
}
