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
    string s;
    cin >> s;

    rep(i, 2) {
        rep(j, 2) {
            vector<char> ans(N);
            if (i == 0) {
                ans[0] = 'S';
            } else {
                ans[0] = 'W';
            }
            if (j == 0) {
                ans[1] = 'S';
            } else {
                ans[1] = 'W';
            }
            for (ll k = 2; k < N; k++) {
                if (ans[k - 1] == 'S') {
                    if (s[k - 1] == 'o') {
                        ans[k] = ans[k - 2];
                    } else {
                        if (ans[k - 2] == 'S') {
                            ans[k] = 'W';
                        } else {
                            ans[k] = 'S';
                        }
                    }
                } else {
                    if (s[k - 1] == 'o') {
                        if (ans[k - 2] == 'S') {
                            ans[k] = 'W';
                        } else {
                            ans[k] = 'S';
                        }
                    } else {
                        ans[k] = ans[k - 2];
                    }
                }
            }
            bool ok = true;
            if (ans[0] == 'S') {
                if (s[0] == 'o') {
                    if (ans[1] != ans[N - 1]) {
                        ok = false;
                    }
                } else {
                    if (ans[1] == ans[N - 1]) {
                        ok = false;
                    }
                }
            } else {
                if (s[0] == 'o') {
                    if (ans[1] == ans[N - 1]) {
                        ok = false;
                    }
                } else {
                    if (ans[1] != ans[N - 1]) {
                        ok = false;
                    }
                }
            }
            if (ans[N - 1] == 'S') {
                if (s[N - 1] == 'o') {
                    if (ans[N - 2] != ans[0]) {
                        ok = false;
                    }
                } else {
                    if (ans[N - 2] == ans[0]) {
                        ok = false;
                    }
                }
            } else {
                if (s[N - 1] == 'o') {
                    if (ans[N - 2] == ans[0]) {
                        ok = false;
                    }
                } else {
                    if (ans[N - 2] != ans[0]) {
                        ok = false;
                    }
                }
            }
            if (!ok) continue;
            rep(k, N) {
                cout << ans[k];
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
