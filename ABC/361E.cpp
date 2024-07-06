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
void outv(const vector<T> &v) {
    for (const auto &e : v) {
        cout << e << " ";
    }
    cout << endl;
}

template <typename T>
struct Edge {
    int to;
    T cost;
};
using Graph = vector<vector<Edge<long long>>>;

template <typename T>
pair<T, int> dfs(const Graph &G, int u, int par) {
    pair<T, int> ret = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs<T>(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
template <typename T>
T tree_diamiter(const Graph &G) {
    pair<T, int> p = dfs<T>(G, 0, -1);
    pair<T, int> q = dfs<T>(G, p.second, -1);
    return q.first;
}

int main() {
    ll N;
    cin >> N;
    Graph edges(N);
    ll sum = 0;
    rep(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
        sum += w;
    }
    ll ans = tree_diamiter<ll>(edges);
    
    ans = -ans;
    ans += 2 * sum;
    cout << ans << endl;

    return 0;
}
