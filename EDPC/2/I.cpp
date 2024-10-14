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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vector<ld> p(N);
    rep(i, N) cin >> p[i];

    vector<vector<ld>> dp(N + 1, vector<ld>(N + 1, 0));
    dp[0][0] = 1;
    rep(i, N + 1) {
        rep(j, N + 1) {
            ll now = i + j;
            if (now == 0) continue;
            if (now > N) break;
            if (i > 0) {
                dp[i][j] += dp[i - 1][j] * p[now - 1];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1] * (1 - p[now - 1]);
            }
        }
    }

    ld ans = 0;
    rep(i, N + 1) {
        ll j = N - i;
        if (i > j) {
            ans += dp[i][j];
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
