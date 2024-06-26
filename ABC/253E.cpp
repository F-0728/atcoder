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
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<mint>> dp(N + 1, vector<mint>(M, 0));
    vector<mint> cSum(M + 1, 0);
    rep(i, M) dp.at(1).at(i) = 1;
    rep(i, M) cSum.at(i + 1) = cSum.at(i) + dp.at(1).at(i);
    rep(i, N - 1) {
        rep(j, M) {
            if (K == 0) {
                dp.at(i + 2).at(j) = cSum.at(M);
                if (j == M - 1) {
                    rep(k, M) cSum.at(k + 1) = cSum.at(k) + dp.at(i + 2).at(k);
                }
                continue;
            }
            if (j + K < M) {
                dp.at(i + 2).at(j) += cSum.at(M);
                dp.at(i + 2).at(j) -= cSum.at(j + K);
            }
            if (j - K >= 0) {
                dp.at(i + 2).at(j) += cSum.at(j - K + 1);
            }
        }
        cSum.at(0) = 0;
        rep(j, M) cSum.at(j + 1) = cSum.at(j) + dp.at(i + 2).at(j);
    }
    mint ans = 0;
    rep(i, M) ans += dp.at(N).at(i);
    cout << ans.val() << endl;
    // rep(i, N + 1) {
        // rep(j, M) {
        //     cout << dp.at(N).at(j).val() << " ";
        // }
        // cout << endl;
    // }

    return 0;
}
