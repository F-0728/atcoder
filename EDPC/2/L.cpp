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
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll dp(N, vll(N, 0));
    bool taroLast = true;
    if (N % 2 == 0) {
        taroLast = false;
    }
    rep(i, N) {
        if (taroLast) {
            dp[i][i] = A[i];
        } else {
            dp[i][i] = -A[i];
        }
    }
    for (ll l = 2; l <= N; l++) {
        bool minus = (taroLast && (l % 2 == 0)) || (!taroLast && (l % 2 == 1));
        rep(i, N - l + 1) {
            ll j = i + l - 1;
            if (minus) {
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j]);
            } else {
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j]);
            }
        }
    }

    cout << dp[0][N - 1] << endl;

    return 0;
}
