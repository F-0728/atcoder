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
    ll N, M;
    cin >> N >> M;
    vvll invG(N);
    scc_graph G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G.add_edge(a, b);
        invG[b].push_back(a);
    }
    auto scc = G.scc();

    vll dp(N, 0);

    ll ans = 0;
    for (auto& v : scc) {
        ll newv = v[0];
        for (ll prev : invG[newv]) {
            dp[newv] = max(dp[newv], dp[prev] + 1);
        }
    }

    rep(i, N) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
