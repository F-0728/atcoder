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
    vvll action(N, vll(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> action[i][j];
        }
    }
    vvll dp(N + 1, vll(3, 0));
    rep(i, N) {
        dp[i + 1][0] = max(dp[i][1] + action[i][0], dp[i][2] + action[i][0]);
        dp[i + 1][1] = max(dp[i][0] + action[i][1], dp[i][2] + action[i][1]);
        dp[i + 1][2] = max(dp[i][0] + action[i][2], dp[i][1] + action[i][2]);
    }

    ll ans = max(dp[N][0], max(dp[N][1], dp[N][2]));

    cout << ans << endl;

    return 0;
}
