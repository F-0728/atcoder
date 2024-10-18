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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;

    vvll blocks(N, vll(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> blocks[i][j];
        }
    }
    sort(blocks.begin(), blocks.end(), [](vll a, vll b) {
        return a[0] + a[1] < b[0] + b[1];
    });

    vvll dp(N + 1, vll(2e4 + 5, -INF));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, 2e4 + 1) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j <= blocks[i][1] && j + blocks[i][0] <= 2e4) {
                dp[i + 1][j + blocks[i][0]] = max(dp[i + 1][j + blocks[i][0]], dp[i][j] + blocks[i][2]);
            }
        }
    }

    ll ans = 0;
    rep(i, 2e4 + 1) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}
