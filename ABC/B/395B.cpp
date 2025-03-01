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

int main() {
    ll N;
    cin >> N;

    vector<vector<char>> ans(N, vector<char>(N, '.'));
    if (N % 2 == 1) {
        rep(i, N / 2) {
            rep(j, N) {
                if (i % 2 == 0) {
                    if (j >= i && j < N - i) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                    } else if (j % 2 == 0) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                    }
                } else {
                    if (j % 2 == 0) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                    }
                    if (j >= i && j < N - i) {
                        ans[i][j] = '.';
                        ans[N - i - 1][j] = '.';
                    }
                }
            }
        }

        if (N % 2 == 1) {
            rep(j, N) {
                if (j % 2 == 0) {
                    ans[N / 2][j] = '#';
                }
            }
        }
    } else {
        rep(i, N / 2) {
            rep(j, N / 2) {
                if (i % 2 == 0) {
                    if (j >= i && j < N - i) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                        ans[i][N - j - 1] = '#';
                        ans[N - i - 1][N - j - 1] = '#';
                    } else if (j % 2 == 0) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                        ans[i][N - j - 1] = '#';
                        ans[N - i - 1][N - j - 1] = '#';
                    }
                } else {
                    if (j % 2 == 0) {
                        ans[i][j] = '#';
                        ans[N - i - 1][j] = '#';
                        ans[i][N - j - 1] = '#';
                        ans[N - i - 1][N - j - 1] = '#';
                    }
                    if (j >= i && j < N - i) {
                        ans[i][j] = '.';
                        ans[N - i - 1][j] = '.';
                        ans[i][N - j - 1] = '.';
                        ans[N - i - 1][N - j - 1] = '.';
                    }
                }
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
