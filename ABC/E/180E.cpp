#include <atcoder/all>
#include <bitset>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
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
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vvll dist(N, vll(N, INF));
    vvll cities(N);
    rep(i, N) {
        ll x, y, p;
        cin >> x >> y >> p;
        cities[i] = {x, y, p};
    }

    rep(i, N) {
        rep(j, N) {
            ll cost = abs(cities[i][0] - cities[j][0]) +
                      abs(cities[i][1] - cities[j][1]);
            cost += max(0LL, cities[j][2] - cities[i][2]);
            dist[i][j] = cost;
        }
    }

    ll ans = INF;
    vvll dp(N, vll(1 << N, INF));
    dp[0][0] = 0;
    rep(bit, 1 << N) {
        rep(i, N) {
            rep(j, N) {
                if (bit & (1 << j)) {
                    continue;
                }
                ll next = bit | (1 << j);
                dp[j][next] = min(dp[j][next], dp[i][bit] + dist[i][j]);
            }
        }
    }

    cout << dp[0][(1 << N) - 1] << endl;

    return 0;
}
