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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vvll> G(N);
    rep(i, M) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        G[a].push_back({b, d});
        G[b].push_back({a, d});
    }

    vpll events(K + 1);
    events[0] = {0, 0};
    rep(i, K) {
        ll c, t;
        cin >> c >> t;
        c--;
        events[i + 1] = {t, c};
    }
    sort(events.begin(), events.end());

    vvll dist(N, vll(N, INF));
    rep(i, N) {
        ll start = i;
        dist[start][start] = 0;
        priority_queue<pll, vpll, greater<pll>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dist[start][v] < d) continue;
            for (auto newv : G[v]) {
                ll nv = newv[0];
                ll nd = newv[1];
                if (dist[start][nv] > d + nd) {
                    dist[start][nv] = d + nd;
                    pq.push({dist[start][nv], nv});
                }
            }
        }
    }

    vll dp(K + 1, -INF);
    dp[0] = 0;
    rep(i, K + 1) {
        ll tI = events[i].first;
        ll cI = events[i].second;
        for (ll j = i + 1; j < K + 1; j++) {
            ll tJ = events[j].first;
            ll cJ = events[j].second;
            if (tJ - tI >= dist[cI][cJ]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;

    return 0;
}
