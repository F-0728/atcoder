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
    ll N, X, K;
    cin >> N >> X >> K;
    vector<vpll> p(N);
    rep(i, N) {
        ll P, U, C;
        cin >> P >> U >> C;
        C--;
        p.at(C).push_back({P, U});
    }
    

    vvll dp(N + 1, vll(X + 1, -INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, X + 1) {
            dp.at(i + 1).at(j) = dp.at(i).at(j);
        }
        for (auto [P, U] : p.at(i)) {
            for (ll j = X; j >= P; j--) {
                dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), max(dp.at(i).at(j - P) + U + K, dp.at(i + 1).at(j - P) + U));
            }
        }
        for (ll j = 0; j < X; j++) {
            dp.at(i + 1).at(j + 1) = max(dp.at(i + 1).at(j), dp.at(i + 1).at(j + 1));
        }
    }


    cout << dp.at(N).at(X) << endl;

    return 0;
}
