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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vpll pq(N - 1);
    rep(i, N - 1) {
        cin >> pq[i].first >> pq[i].second;
        pq[i].first--;
        pq[i].second--;
    }

    dsu d(N);
    vvll G(2 * N - 1);
    vmint size(2 * N - 1, 0);
    vll lastgame(N);
    rep(i, N) {
        lastgame[i] = N + i - 1;
        size[N + i - 1] = 1;
    }

    rep(i, N - 1) {
        ll l = d.leader(pq[i].first);
        ll r = d.leader(pq[i].second);
        G[i].push_back(lastgame[l]);
        G[i].push_back(lastgame[r]);
        size[i] = size[lastgame[l]] + size[lastgame[r]];
        d.merge(l, r);
        lastgame[d.leader(l)] = i;
    }

    vmint ans(2 * N - 1, 0);
    ll start = N - 2;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        mint base = 0;
        for (auto nx : G[now]) {
            base += size[nx];
        }
        for (auto nx : G[now]) {
            ans[nx] = size[nx] / base + ans[now];
            q.push(nx);
        }
    }

    for (ll i = N - 1; i < 2 * N - 1; i++) {
        cout << ans[i].val() << " ";
    }
    cout << endl;

    return 0;
}
