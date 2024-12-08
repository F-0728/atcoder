#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvll edges(M);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.at(i) = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    dsu d(N);
    vll countA(N, 0);
    vll countB(N, 0);

    vll A(K);
    vll B(K);
    rep(i, K) {
        cin >> A.at(i);
        A.at(i)--;
        countA.at(A.at(i))++;
    }
    rep(i, K) {
        cin >> B.at(i);
        B.at(i)--;
        countB.at(B.at(i))++;
    }

    ll ans = 0;
    rep(i, M) {
        ll w = edges.at(i).at(0);
        ll u = edges.at(i).at(1);
        ll v = edges.at(i).at(2);
        if (d.same(u, v)) continue;
        ll au = countA.at(d.leader(u));
        ll bu = countB.at(d.leader(u));
        ll av = countA.at(d.leader(v));
        ll bv = countB.at(d.leader(v));
        ll match = min(au, bv) + min(av, bu);
        ans += match * w;
        d.merge(u, v);
        countA.at(d.leader(u)) = max(0LL, au + av - bu - bv);
        countB.at(d.leader(u)) = max(0LL, bu + bv - au - av);
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
