#include <atcoder/all>
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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

vvll dp;
vll cSum;
ll dp_mem(ll l, ll r) {
    if (dp[l][r] != INF) return dp[l][r];
    ll minCost = INF;
    for (ll i = l; i < r; i++) {
        minCost = min(minCost, dp_mem(l, i) + dp_mem(i + 1, r));
    }
    return dp[l][r] = minCost + cSum[r + 1] - cSum[l];
}

int main() {
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) cin >> a[i];
    cSum.resize(N + 1, 0);
    rep(i, N) cSum[i + 1] = cSum[i] + a[i];

    dp.resize(N, vll(N, INF));
    rep(i, N) dp[i][i] = 0;

    cout << dp_mem(0, N - 1) << endl;

    return 0;
}
