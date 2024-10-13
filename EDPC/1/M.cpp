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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vll candies(N);
    rep(i, N) cin >> candies.at(i);
    vector<vector<mint>> dp(N + 1, vector<mint>(K + 1, 0));
    dp.at(0).at(0) = 1;
    rep(i, N + 1) {
        rep(j, K + 1) {
            if (i == 0) continue;
            if (i == 1) {
                if (j <= candies.at(0)) {
                    dp.at(i).at(j) = 1;
                }
                continue;
            }
            if (j > 0) dp.at(i).at(j) += dp.at(i).at(j - 1);
            if (i > 0) {
                dp.at(i).at(j) += dp.at(i - 1).at(j);
                if (j - candies.at(i - 1) - 1 >= 0) {
                    dp.at(i).at(j) -=
                        dp.at(i - 1).at(j - candies.at(i - 1) - 1);
                }
            }
        }
    }

    cout << dp.at(N).at(K).val() << endl;

    return 0;
}
