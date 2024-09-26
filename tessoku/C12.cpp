#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
//using mint = modint998244353;
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
    ll N, M, K;
    cin >> N >> M >> K;
    vpll link(M);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        link[i] = {A, B};
    }

    vvll dp(K + 1, vll(N + 1, -INF));
    dp[0][0] = 0;
    rep(i, K) {
        rep(j, N + 1) {
            ll m = -INF;
            rep(k, j) {
                ll now = 0;
                rep(l, M) {
                    if (link[l].first > k && link[l].second <= j) {
                        now++;
                    }
                }
                m = max(m, dp[i][k] + now);
            }
            dp[i + 1][j] = m;
        }
    }
    cout << dp[K][N] << endl;

    return 0;
}
