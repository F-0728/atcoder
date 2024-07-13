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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

vll leaves;
void dfs(ll v, ll p, vvll& G, vpll& LR) {
    for (ll u : G[v]) {
        if (u == p) continue;
        if (G[u].size() == 1) {
            leaves.push_back(u);
            LR[u] = {leaves.size(), leaves.size()};
        }
        dfs(u, v, G, LR);
        // rep(i, LR.size()) {
        //     cout << LR[i].first << " " << LR[i].second << endl;
        // }
        LR[v].first = min(LR[v].first, LR[u].first);
        LR[v].second = max(LR[v].second, LR[u].second);
    }
}

int main() {
    ll N;
    cin >> N;
    vvll G(N);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vpll LR(N, {INF, -1});
    dfs(0, -1, G, LR);
    rep(i, N) { cout << LR[i].first << " " << LR[i].second << endl; }

    return 0;
}
