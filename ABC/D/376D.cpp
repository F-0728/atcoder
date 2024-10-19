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
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;

    scc_graph G(N);
    vvll g(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G.add_edge(a, b);
        g[a].push_back(b);
    }

    vvll gnew(N);

    auto scc = G.scc();
    for (auto& v : scc) {
        for (auto& e : v) {
            if (e == 0) {
                if (v.size() == 1) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    for (auto& f : v) {
                        for (auto& h : g[f]) {
                            gnew[f].push_back(h);
                        }
                    }
                    break;
                }
            }
        }
    }

    ll ans = INF;
    queue<pll> q;
    q.push({0, 0});
    vll dist(N, INF);
    dist[0] = 0;
    while (!q.empty()) {
        auto [now, d] = q.front(); q.pop();
        if (now == 0 && d != 0) {
            ans = d;
            break;
        }
        for (auto& e : gnew[now]) {
            if (dist[e] == INF || e == 0) {
                dist[e] = d + 1;
                q.push({e, d + 1});
            }
        }
    }

    cout << ans << endl;

    return 0;
}
