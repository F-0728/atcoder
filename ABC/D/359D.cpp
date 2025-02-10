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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vbool Aok(1 << (K - 1), true);
    vbool Bok(1 << (K - 1), true);
    rep(i, 1 << (K - 1)) {
        string suf;
        rep(j, K - 1) {
            if (i & (1 << j)) {
                suf += 'A';
            } else {
                suf += 'B';
            }
        }
        string revsuf = suf;
        reverse(revsuf.begin(), revsuf.end());
        // cout << suf << " " << revsuf << endl;
        if (suf.substr(0, K - 2) == revsuf.substr(1)) {
            if (revsuf.at(0) == 'A') {
                Aok.at(i) = false;
            } else {
                Bok.at(i) = false;
            }
        }
    }

    // outv(Aok);
    // outv(Bok);

    vvmint dp(N + 1, vmint(1 << (K - 1), 0));
    dp.at(0).at(0) = 1;
    rep(i, N) {
        rep(j, 1 << (K - 1)) {
            if (dp.at(i).at(j).val() == 0) continue;
            if (S.at(i) != 'B') {
                if (Aok.at(j) || i < K - 1) {
                    dp.at(i + 1).at(((j << 1) & ((1 << (K - 1)) - 1)) + 1) += dp.at(i).at(j);
                }
            }
            if (S.at(i) != 'A') {
                if (Bok.at(j) || i < K - 1) {
                    dp.at(i + 1).at((j << 1) & ((1 << (K - 1)) - 1)) += dp.at(i).at(j);
                }
            }
        }
    }

    mint ans = 0;
    rep(j, 1 << (K - 1)) {
        ans += dp.at(N).at(j);
    }
    cout << ans.val() << endl;

    // outvvmint(dp);

    return 0;
}
