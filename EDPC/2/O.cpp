#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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

    // 男性i人目までに女性jが選ばれているときの場合の数
    vector<vector<mint>> dp(N + 1, vector<mint>(1 << N, 0));
    dp[0][0] = 1;
    rep(i, N + 1) {
        rep(j, 1 << N) {
            if (popcount(unsigned(j)) != i + 1) continue;
            rep(k, N) {
                if (!(j & (1 << k))) continue;
                if (A[i][k] == 0) continue;
                dp[i + 1][j] += dp[i][j ^ (1 << k)];
            }
        }
    }

    cout << dp[N][(1 << N) - 1].val() << endl;

    return 0;
}
