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
    vll a(N);
    rep(i, N) cin >> a[i];

    mint ans = 0;

    // i個選ぶことを固定，j(+1)番目までみてk個選んだとき，modiがlになる
    rep(i, N + 1) {
        if (i == 0) continue;
        vector<vvmint> dp(N + 1, vvmint(N + 1, vmint(i, 0)));
        dp[0][0][0] = 1;
        rep(j, N) {
            rep(k, j + 1) {
                rep(l, i) {
                    dp[j + 1][k][l] += dp[j][k][l];
                    if (k + 1 <= N) {
                        dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
                    }
                }
            }
        }
        ans += dp[N][i][0];
    }

    cout << ans.val() << endl;

    return 0;
}
