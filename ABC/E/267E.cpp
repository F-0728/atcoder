#include <atcoder/all>
#include <bitset>
#include <chrono>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
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
    vll A(N);
    rep(i, N) { cin >> A[i]; }

    vvll G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N) { sort(G[i].begin(), G[i].end()); }

    priority_queue<pll, vpll, greater<pll>> pq;

    vll cost(N, 0);
    rep(i, N) {
        for (auto& e : G[i]) {
            cost[i] += A[e];
        }
    }
    vbool erased(N, false);
    rep(i, N) { pq.push({cost[i], i}); }
    ll ans = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top();
        pq.pop();
        if (erased[v]) {
            continue;
        }
        ans = max(ans, c);
        erased[v] = true;
        for (auto& e : G[v]) {
            if (erased[e]) {
                continue;
            }
            cost[e] -= A[v];
            pq.push({cost[e], e});
        }
    }

    cout << ans << endl;

    return 0;
}
