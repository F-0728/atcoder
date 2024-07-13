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
    ll N, M;
    cin >> N >> M;
    vector<vpll> G(N);
    vll weightV(N);
    rep(i, N) { cin >> weightV[i]; }
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vll dist(N, INF);
    dist.at(0) = weightV.at(0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist.at(0), 0});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist.at(v) < d) {
            continue;
        }
        for (auto [nv, w] : G.at(v)) {
            if (dist.at(nv) > dist.at(v) + w + weightV.at(nv)) {
                dist.at(nv) = dist.at(v) + w + weightV.at(nv);
                pq.push({dist.at(nv), nv});
            }
        }
    }
    rep(i, N) {
        if (i == 0) continue;
        cout << dist.at(i) << " ";
    }
    cout << endl;

    return 0;
}
