#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
//using mint = modint998244353;
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
    ll N, M, K, S;
    cin >> N >> M >> K >> S;
    vvll G(N + 1);
    vll danger(N + 1, -1);
    vll dame(K);
    ll P, Q;
    cin >> P >> Q;
    rep(i, K) {
        ll C;
        cin >> C;
        C--;
        dame[i] = C;
        G[C].push_back(N);
        G[N].push_back(C);
    }
    sort(dame.begin(), dame.end());

    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    priority_queue<pll> pq;
    pq.push({S + 1, N});
    while (!pq.empty()) {
        auto [rem, v] = pq.top(); pq.pop();
        // cout << rem << " " << v << endl;
        if (danger[v] >= rem) continue;
        danger[v] = rem;
        if (rem == 0) continue;
        for (auto nv : G[v]) {
            if (danger[nv] < rem - 1) {
                pq.push({rem - 1, nv});
            }
        }
    }

    priority_queue<pll, vpll, greater<pll>> pq2;
    vll cost(N, INF);
    cost[0] = 0;
    pq2.push({0, 0});
    while (!pq2.empty()) {
        auto [c, v] = pq2.top(); pq2.pop();
        // cout << c << " " << v << endl;
        if (c >= cost[v] && v != 0) continue;
        if (find(dame.begin(), dame.end(), v) != dame.end()) continue;
        cost[v] = c;
        if (v == N - 1) continue;
        for (ll nv : G[v]) {
            if (nv == N) continue;
            if (danger[nv] == -1) {
                if (c + P < cost[nv]) {
                    pq2.push({c + P, nv});
                }
            } else {
                if (c + Q < cost[nv]) {
                    pq2.push({c + Q, nv});
                }
            }
        }
    }

    ll ans = cost[N - 1];
    if (danger[N - 1] == -1) {
        ans -= P;
    } else {
        ans -= Q;
    }
    cout << ans << endl;

    return 0;
}
