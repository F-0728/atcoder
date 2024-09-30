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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    ll N;
    cin >> N;
    vvll work(N, vll(3));
    rep(i, N) cin >> work[i][0] >> work[i][1] >> work[i][2];

    sort(work.begin(), work.end());

    vvll dp(N + 1, vll(5001, 0));

    rep(i, N) {
        ll D = work[i][0];
        ll C = work[i][1];
        ll S = work[i][2];
        rep(j, 5001) { dp[i + 1][j] = dp[i][j]; }
        for (ll j = C; j <= D; j++) { dp[i + 1][j] = max(dp[i][j], dp[i][j - C] + S); }
    }

    ll ans = 0;
    rep(i, 5001) { ans = max(ans, dp[N][i]); }

    cout << ans << endl;

    return 0;
}
