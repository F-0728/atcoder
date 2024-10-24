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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll P(N);
    rep(i, N) cin >> P[i];

    vld pow09(5001, 1);
    rep(i, 5000) {
        pow09.at(i + 1) = pow09.at(i) * 0.9;
    }
    vld cSum(5002, 0);
    rep(i, 5001) {
        cSum.at(i + 1) = cSum.at(i) + pow09.at(i);
    }
    ld ans = -INF;
    // i番目まで見てj個選んだときの最大値
    vvld dp(N + 1 , vld(N + 1, 0));
    rep(j, N) {
        rep(k, j + 1) {
            dp.at(j + 1).at(k) = max(dp.at(j + 1).at(k), dp.at(j).at(k));
        }
        rep(k, j + 1) {
            ld next = P.at(j);
            dp.at(j + 1).at(k + 1) = max(dp.at(j + 1).at(k + 1), 0.9 * dp.at(j).at(k) + next);
        }
    }
    // outv(dp.at(N));
    for (ll i = 1; i <= N; i++) {
        ld a = cSum.at(i);
        ld b = 1200 / sqrtl(i);
        ans = max(ans, dp.at(N).at(i) / a - b);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
