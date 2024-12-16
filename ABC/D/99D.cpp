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
    ll N, C;
    cin >> N >> C;
    vvll D(C, vll(C));
    rep(i, C) {
        rep(j, C) {
            cin >> D[i][j];
        }
    }

    vvll c(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vvll cost(3, vll(C, INF));
    rep(i, C) {
        ll cost0 = 0, cost1 = 0, cost2 = 0;
        rep(x, N) {
            rep(y, N) {
                if ((x + y) % 3 == 0) {
                    cost0 += D[c[x][y]][i];
                } else if ((x + y) % 3 == 1) {
                    cost1 += D[c[x][y]][i];
                } else {
                    cost2 += D[c[x][y]][i];
                }
            }
        }
        cost[0][i] = cost0;
        cost[1][i] = cost1;
        cost[2][i] = cost2;
    }

    ll ans = INF;
    rep(i, C) {
        rep(j, C) {
            if (i == j) continue;
            rep(k, C) {
                if (i == k || j == k) continue;
                ll sum = 0;
                sum += cost[0][i];
                sum += cost[1][j];
                sum += cost[2][k];
                ans = min(ans, sum);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
