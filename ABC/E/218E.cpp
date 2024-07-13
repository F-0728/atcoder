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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

struct Edge {
    ll u, v, cost;
    bool operator<(const Edge& other) const { return (cost < other.cost); }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    rep(i, M) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        edges[i].u--;
        edges[i].v--;
    }
    sort(edges.begin(), edges.end());
    ll sum = 0;
    rep(i, M) {
        sum += edges[i].cost;
    }
    dsu d(N);
    ll ans = 0;
    for (Edge e : edges) {
        if (d.same(e.u, e.v)) {
            if (e.cost < 0) {
                ans += e.cost;
            }
            continue;
        }
        d.merge(e.u, e.v);
        ans += e.cost;
    }
    cout << sum - ans << endl;

    return 0;
}
