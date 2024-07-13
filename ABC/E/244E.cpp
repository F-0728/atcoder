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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--; T--; X--;
    vvll G(N);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<vector<vector<mint>>> dp(K + 1, vector<vector<mint>>(N, vector<mint>(2, 0)));
    dp[0][S][0] = 1;
    rep(k, K){
        rep(v, N){
            for(ll u : G[v]){
                if (u != X) {
                    dp[k + 1][u][0] += dp[k][v][0];
                    dp[k + 1][u][1] += dp[k][v][1];
                } else {
                    dp[k + 1][u][0] += dp[k][v][1];
                    dp[k + 1][u][1] += dp[k][v][0];
                
                }
            }
        }
    }
    cout << dp.at(K).at(T).at(0).val() << endl;
    // rep(i, K + 1) {
    //     cout << dp.at(i).at(T).at(0).val() << " " << dp.at(i).at(T).at(1).val() << endl;
    // }

    return 0;
}
