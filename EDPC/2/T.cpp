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
    string s;
    cin >> s;

    vector<vector<mint>> dp(N, vector<mint>(N + 1, 0));
    rep(i, N) {
        dp[0][i] = 1;
    }
    rep(i, N - 1) {
        vector<mint> prevcSum(N + 1, 0);
        rep(j, N) {
            prevcSum[j + 1] = prevcSum[j] + dp[i][j];
        }
        if (s[i] == '<') {
            rep(j, N - i - 1) {
                dp[i + 1][j] = prevcSum[N - i] - prevcSum[j + 1];
            }
        } else {
            rep(j, N - i - 1) {
                dp[i + 1][j] = prevcSum[j + 1];
            }
        }
    }

    cout << dp[N - 1][0].val() << endl;

    // rep(i, N) {
    //     rep(j, N + 1) {
    //         cout << dp[i][j].val() << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
