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
    vll scores(N);
    rep(i, N) cin >> scores.at(i);
    vvll dp(N, vll(N));
    rep(i, N) dp.at(i).at(i) = scores.at(i);
    rep(i, N) {
        if (i == 0) continue;
        rep(j, N - i) {
            dp.at(j).at(j + i) = max(scores.at(j) - dp.at(j + 1).at(j + i), scores.at(j + i) - dp.at(j).at(j + i - 1));
        }
    }
    cout << dp.at(0).at(N - 1) << endl;

    return 0;
}
