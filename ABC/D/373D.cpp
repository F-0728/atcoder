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

    dsu d(N);

    vector<vvll> G(N);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, -w});
        d.merge(u, v);
    }

    vll ans(N, INF * 2);
    vll starts;
    
    auto g = d.groups();
    for (auto v : g) {
        starts.push_back(v[0]);
        ans[v[0]] = 0;
    }

    sort(starts.begin(), starts.end());

    queue<pll> q;
    for (auto start : starts) {
        q.push({start, 0});
    }

    while (!q.empty()) {
        auto [now, val] = q.front();
        q.pop();
        // cout << now << endl;
        if (ans[now] != 2 * INF) {
            if (lower_bound(starts.begin(), starts.end(), now) == upper_bound(starts.begin(), starts.end(), now)) {
                continue;
            }
        }
        ans[now] = val;
        for (auto nv : G[now]) {
            ll to = nv[0];
            ll w = nv[1];
            if (ans[to] != 2 * INF) continue;
            q.push({to, val + w});
        }
    }

    outv(ans);

    return 0;
}
