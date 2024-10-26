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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vll H(N);
    rep(i, N) cin >> H[i];

    vector<vpll> G(N);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        if (H[u] >= H[v]) {
            G[u].push_back({v, 0});
            G[v].push_back({u, H[u] - H[v]});
        } else {
            G[u].push_back({v, H[v] - H[u]});
            G[v].push_back({u, 0});
        }
    }

    vll dist(N, INF);
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] <= d) continue;
        dist[v] = d;
        for (auto [nv, nd] : G[v]) {
            if (dist[nv] > d + nd) {
                pq.push({d + nd, nv});
            }
        }
    }

    ll ans = INF;
    rep(i, N) {
        ans = min(ans, dist[i] + H[i]);
    }

    // outv(dist);

    cout << H[0] - ans << endl;


    return 0;
}
