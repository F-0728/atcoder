#include <atcoder/all>
#include <iostream>
#include <vector>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>

int main() {
    ll N, M;
    cin >> N >> M;
    vvll edges(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.at(a).push_back(b);
    }

    scc_graph g(N);
    rep(i, N) {
        for (ll v : edges.at(i)) {
            g.add_edge(i, v);
        }
    }

    vector<vector<int>> scc = g.scc();
    vll dp(N, 0);

    for (vector<int> s : scc) {
        for (ll u : s) {
            for (ll v : edges.at(u)) {
                dp.at(v) = max(dp.at(v), dp.at(u) + 1);
            }
        }
    }

    ll ans = 0;
    rep(i, N) {
        ans = max(ans, dp.at(i));
    }
    cout << ans << endl;

    return 0;
}
