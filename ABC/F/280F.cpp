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
    ll N, M, Q;
    cin >> N >> M >> Q;
    dsu d(N);
    vector<vvll> G(N);
    rep(i, M) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        d.merge(A, B);
        G[A].push_back({B, C});
        G[B].push_back({A, -C});
    }

    auto groups = d.groups();
    vll dist(N, INF);
    for (auto group : groups) {
        ll l = d.leader(group[0]);
        dist[l] = 0;
        bool isINF = false;
        queue<ll> q;
        q.push(l);
        while (!q.empty()) {
            ll p = q.front();
            q.pop();
            for (auto e : G[p]) {
                ll to = e[0];
                ll cost = e[1];
                if (dist[to] == INF) {
                    dist[to] = dist[p] + cost;
                    q.push(to);
                } else {
                    if (dist[to] != dist[p] + cost) {
                        isINF = true;
                        break;
                    }
                }
            }
        }
        if (isINF) {
            for (auto g : group) {
                dist[g] = INF;
            }
        }
    }

    rep(i, Q) {
        ll X, Y;
        cin >> X >> Y;
        X--; Y--;
        if (d.same(X, Y)) {
            if (dist[X] == INF) {
                cout << "inf" << endl;
            } else {
                cout << dist[Y] - dist[X] << endl;
            }
        } else {
            cout << "nan" << endl;
        }
    }



    return 0;
}
