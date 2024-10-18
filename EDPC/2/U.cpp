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
    vvll A(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            cin >> A[i][j];
        }
    }

    vll dp(1 << N, -INF);
    dp[0] = 0;
    rep(i, 1 << N) {
        if (i == 0) continue;
        ll res = 0;
        rep(j, N) {
            rep(k, j + 1) {
                if ((i & (1 << j)) && (i & (1 << k))) {
                    res += A[j][k];
                }
            }
        }
        dp[i] = max(dp[i], res);
        for (ll j = i; j > 0; j = (j - 1) & i) {
            dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
