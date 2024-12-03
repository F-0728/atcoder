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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) {
        cin >> S[i];
    }

    vvmint ans(H, vmint(W, 0));
    vvmint dprow(H, vmint(W, 0));
    vvmint dpcol(H, vmint(W, 0));
    vvmint dpdiag(H, vmint(W, 0));
    ans[0][0] = 1;
    dprow[0][0] = 1;
    dpcol[0][0] = 1;
    dpdiag[0][0] = 1;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            if (i > 0) {
                dprow[i][j] = dprow[i - 1][j] + ans[i - 1][j];
            }
            if (j > 0) {
                dpcol[i][j] = dpcol[i][j - 1] + ans[i][j - 1];
            }
            if (i > 0 && j > 0) {
                dpdiag[i][j] = dpdiag[i - 1][j - 1] + ans[i - 1][j - 1];
            }
            if (i > 0 && j > 0) {
                ans[i][j] = dprow[i][j] + dpcol[i][j] + dpdiag[i][j];
            } else if (i > 0) {
                ans[i][j] = dprow[i][j];
            } else if (j > 0) {
                ans[i][j] = dpcol[i][j];
            }
        }
    }

    mint res = ans[H - 1][W - 1];
    res /= 2;

    cout << res.val() << endl;

    return 0;
}
