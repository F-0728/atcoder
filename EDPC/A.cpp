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
    vll height(N);
    rep(i, N) cin >> height.at(i);
    vll dp(N + 1, INF);
    dp.at(0) = 0;
    rep(i, N) {
        if (i == 0) continue;
        if (i == 1) {
            dp.at(i) = dp.at(i - 1) + abs(height.at(i) - height.at(i - 1));
            continue;
        }
        dp.at(i) = min(dp.at(i - 1) + abs(height.at(i) - height.at(i - 1)), dp.at(i - 2) + abs(height.at(i) - height.at(i - 2)));
    }
    cout << dp.at(N - 1) << endl;

    return 0;
}
