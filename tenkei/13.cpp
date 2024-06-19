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

void dijkstra(ll s, vector<vpll>& G, vll& dist) {
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist.at(v) < d) {
            continue;
        }
        for (auto [nv, c] : G.at(v)) {
            if (dist.at(nv) > d + c) {
                dist.at(nv) = d + c;
                pq.push({dist.at(nv), nv});
            }
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vpll> G(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G.at(a).push_back({b, c});
        G.at(b).push_back({a, c});
    }
    vll distFromS(N, INF);
    distFromS.at(0) = 0;
    vll distFromT(N, INF);
    distFromT.at(N - 1) = 0;
    dijkstra(0, G, distFromS);
    dijkstra(N - 1, G, distFromT);
    rep(i, N) {
        cout << distFromS.at(i) + distFromT.at(i) << endl;
    }


    return 0;
}
