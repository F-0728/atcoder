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
    vector<double> probability(N);
    rep(i, N) cin >> probability.at(i);
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp.at(0).at(0) = 1;
    rep(i, N) {
        rep(j, N) {
            dp.at(i + 1).at(j + 1) += dp.at(i).at(j) * probability.at(i);
            dp.at(i + 1).at(j) += dp.at(i).at(j) * (1 - probability.at(i));
        }
    }
    double ans = 0;
    for (ll i = N / 2 + 1; i <= N; i++) {
        ans += dp.at(N).at(i);
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
