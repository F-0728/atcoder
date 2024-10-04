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
    vvll G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll K;
    cin >> K;
    map<ll, ll> mp;
    rep(i, K) {
        ll p, d;
        cin >> p >> d;
        p--;
        mp[p] = d;
    }

    vll ans(N, -1);
    
    vvll dist(N, vll(N, INF));
    rep(i, N) {
        dist[i][i] = 0;
        queue<pll> q;
        q.push({i, 0});
        while (!q.empty()) {
            auto [v, d] = q.front();
            q.pop();
            for (auto u : G[v]) {
                if (dist[i][u] != INF) continue;
                dist[i][u] = d + 1;
                q.push({u, d + 1});
            }
        }
    }

    rep(i, N) {
        if (mp.find(i) == mp.end()) continue;
        ll d = mp[i];
        rep(j, N) {
            if (dist[i][j] < d) {
                ans[j] = 0;
            }
        }
    }

    rep(i, N) {
        if (ans[i] == -1) {
            ans[i] = 1;
        }
    }

    for (auto [k, v] : mp) {
        ll distd = 0;
        ll black = 0;
        rep(i, N) {
            if (dist[k][i] < v && ans[i] == 1) {
                No;
                return 0;
            } else if (dist[k][i] == v) {
                distd++;
                if (ans[i] == 1) {
                    black++;
                }
            }
        }
        if (distd != 0 && black == 0) {
            No;
            return 0;
        }
    }

    ll blackCount = 0;
    rep(i, N) {
        if (ans[i] == 1) {
            blackCount++;
        }
    }
    if (blackCount == 0) {
        No;
        return 0;
    }

    Yes;
    rep(i, N) {
        cout << ans[i];
    }
    cout << endl;


    return 0;
}
