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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N * 2);
    rep(i, N * 2) cin >> A[i];

    vvll dp(N * 2, vll(N * 2, INF));
    rep(i, N * 2 - 1) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }

    for (ll len = 2; len < N * 2; len++) {
        rep(l, N * 2 - len) {
            ll r = l + len;
            dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(A[l] - A[r]));
            for (ll k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }

    cout << dp[0][N * 2 - 1] << endl;


    return 0;
}
