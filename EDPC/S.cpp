#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
    string K;
    cin >> K;
    ll D;
    cin >> D;
    ll N = K.size();
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(D, vector<mint>(2, 0)));
    dp.at(0).at(0).at(0) = 1;
    rep(i, N) {
        rep(j, D) {
            rep(k, 10) {
                dp.at(i + 1).at((j + k) % D).at(1) += dp.at(i).at(j).at(1);
            }
            rep(k, K.at(i) - '0') {
                dp.at(i + 1).at((j + k) % D).at(1) += dp.at(i).at(j).at(0);
            }
            dp.at(i + 1).at((j + K.at(i) - '0') % D).at(0) += dp.at(i).at(j).at(0);
        }
    }
    mint ans = dp.at(N).at(0).at(0) + dp.at(N).at(0).at(1) - 1;
    cout << ans.val() << endl;

    return 0;
}
