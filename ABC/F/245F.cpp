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

    vpll edges(M);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        edges[i] = {A, B};
    }

    vbool loopItself(N, false);

    vvll g(N);
    scc_graph G(N);
    rep(i, M) {
        ll A = edges[i].first;
        ll B = edges[i].second;
        G.add_edge(A, B);
        g[A].push_back(B);
        if (A == B) {
            loopItself[A] = true;
        }
    }

    vbool ans(N, false);

    auto scc = G.scc();
    ll n = scc.size();
    for (ll i = n - 1; i >= 0; i--) {
        if (scc[i].size() != 1) {
            for (auto v : scc[i]) {
                ans[v] = true;
            }
            continue;
        }
        if (loopItself[scc[i][0]]) {
            ans[scc[i][0]] = true;
            continue;
        }
        if (g[scc[i][0]].size() != 0) {
            for (auto v : g[scc[i][0]]) {
                if (ans[v]) {
                    ans[scc[i][0]] = true;
                    break;
                }
            }
        }
    }

    ll count = 0;
    rep(i, N) {
        if (ans[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
