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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vvll edges(M, vll(3));
    rep(i, M) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        edges[i] = {u, v, c};
    }
    vector<vvll> G(N);
    vvll queries;
    rep(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            x--;
            queries.push_back({t, x});
        } else {
            ll x, y;
            cin >> x >> y;
            x--; y--;
            queries.push_back({t, x, y});
        }
    }
    reverse(queries.begin(), queries.end());
    vector<bool> blocked(M, false);
    rep(i, Q) {
        if (queries[i][0] == 1) {
            blocked[queries[i][1]] = true;
        }
    }
    rep(i, M) {
        if (!blocked[i]) {
            G[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            G[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
    }

    vvll dist(N, vll(N, INF));
    rep(i, N) {
        dist[i][i] = 0;
        for (auto newv : G[i]) {
            ll to = newv[0], cost = newv[1];
            dist[i][to] = min(dist[i][to], cost);
        }
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vll ans;
    rep(i, Q) {
        ll t = queries[i][0];
        if (t == 1) {
            ll x = queries[i][1];
            vll bridge = edges[x];
            ll u = bridge[0], v = bridge[1], c = bridge[2];
            G[u].push_back({v, c});
            G[v].push_back({u, c});
            dist[u][v] = min(dist[u][v], c);
            dist[v][u] = min(dist[v][u], c);
            rep(j, N) {
                rep(k, N) {
                    dist[j][k] = min(dist[j][k], dist[j][u] + dist[u][v] + dist[v][k]);
                    dist[j][k] = min(dist[j][k], dist[j][v] + dist[v][u] + dist[u][k]);
                }
            }
        } else {
            ans.push_back(dist[queries[i][1]][queries[i][2]]);
        }
    }

    reverse(ans.begin(), ans.end());
    for (ll a : ans) {
        if (a == INF) {
            cout << -1 << endl;
        } else {
            cout << a << endl;
        }
    }

    return 0;
}
