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

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvll edge(2 * N);
    vll dist(2 * N, INF);
    rep(i, M) {
        ll u, v, a;
        cin >> u >> v >> a;
        u--;
        v--;
        if (a == 1) {
            edge.at(u * 2).push_back(v * 2);
            edge.at(v * 2).push_back(u * 2);
        } else {
            edge.at(u * 2 + 1).push_back(v * 2 + 1);
            edge.at(v * 2 + 1).push_back(u * 2 + 1);
        }
    }
    rep(i, K) {
        ll s;
        cin >> s;
        s--;
        edge.at(s * 2).push_back(s * 2 + 1);
        edge.at(s * 2 + 1).push_back(s * 2);
    }
    dist.at(0) = 0;

    deque<pll> q;
    q.push_back({0, 0});
    while (!q.empty()) {
        pll p = q.front();
        q.pop_front();
        ll v = p.first;
        ll d = p.second;
        for (auto u : edge.at(v)) {
            if (floor(u / 2) == floor(v / 2) && u % 2 != v % 2) {
                if (dist.at(u) > d) {
                    dist.at(u) = d;
                    q.push_front({u, d});
                }
                continue;
            }
            if (dist.at(u) > d + 1) {
                dist.at(u) = d + 1;
                q.push_back({u, d + 1});
            }
        }
    }

    if (dist.at(2 * N - 2) == INF && dist.at(2 * N - 1) == INF) {
        cout << -1 << endl;
    } else {
        cout << min(dist.at(2 * N - 2), dist.at(2 * N - 1)) << endl;
    }
    // rep(i, 2) {
    //     cout << dist.at(0).at(i) << " " << dist.at(1).at(i) << " "
    //          << dist.at(2).at(i) << " " << dist.at(3).at(i) << " "
    //          << dist.at(4).at(i) << endl;
    // }

    return 0;
}
