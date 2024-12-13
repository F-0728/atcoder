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
    ll N;
    cin >> N;
    vpll p(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    ll ans = 0;
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            for (ll k = j + 1; k < N; k++) {
                ll x1 = p[j].first - p[i].first;
                ll y1 = p[j].second - p[i].second;
                ll x2 = p[k].first - p[i].first;
                ll y2 = p[k].second - p[i].second;
                if (x1 * y2 == x2 * y1) continue;
                ll x3 = p[k].first - p[j].first;
                ll y3 = p[k].second - p[j].second;
                ll count = 0;
                ll lcm1 = lcm(abs(x1), abs(y1));
                ll lcm2 = lcm(abs(x2), abs(y2));
                ll lcm3 = lcm(abs(x3), abs(y3));
                count += lcm1 + lcm2 + lcm3;
                if (count % 2 == 0) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
