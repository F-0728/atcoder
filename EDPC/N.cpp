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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll slimes(N);
    rep(i, N) cin >> slimes.at(i);
    vll cSum(N + 1, 0);
    rep(i, N) cSum.at(i + 1) = cSum.at(i) + slimes.at(i);
    vvll dp(N + 1, vll(N + 1, -1));
    rep(i, N) dp.at(i).at(i + 1) = 0;
    for (ll w = 2; w <= N; w++) {
        for (ll l = 0; l + w <= N; l++) {
            ll r = l + w;
            ll minCost = INF;
            for (ll m = l + 1; m < r; m++) {
                minCost = min(minCost, dp.at(l).at(m) + dp.at(m).at(r));
            }
            dp.at(l).at(r) = minCost + cSum.at(r) - cSum.at(l);
        }
    }
    
    cout << dp.at(0).at(N) << endl;


    return 0;
}
