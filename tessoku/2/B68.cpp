#include <atcoder/all>
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
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
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
    vll P(N);
    rep(i, N) {
        cin >> P[i];
        P[i] -= 150;
        P[i] *= -1;
    }

    mf_graph<ll> G(N + 2);
    ll s = N, t = N + 1;
    rep(i, N) {
        G.add_edge(s, i, P[i]);
        G.add_edge(i, t, 150);
    }
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G.add_edge(b, a, INF);
    }

    ll mf = G.flow(s, t);
    cout << 150 * N - mf << endl;


    return 0;
}
