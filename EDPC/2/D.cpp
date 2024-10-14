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
    ll N, W;
    cin >> N >> W;
    vpll nimotsu(N);
    rep(i, N) {
        ll w, v;
        cin >> w >> v;
        nimotsu[i] = {w, v};
    }
    
    vvll dp(N + 1, vll(W + 1, -INF));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, W + 1) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + nimotsu[i].first <= W) {
                dp[i + 1][j + nimotsu[i].first] = max(dp[i + 1][j + nimotsu[i].first], dp[i][j] + nimotsu[i].second);
            }
        }
    }

    ll ans = 0;
    rep(i, W + 1) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}
