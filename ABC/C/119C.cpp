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
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << endl;}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << endl; }}

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vll l(N);
    rep(i, N) {
        cin >> l[i];
    }

    ll ans = INF;
    rep(i, power(4, N)) {
        vll a, b, c;
        rep(j, N) {
            ll t = (i / power(4, j)) % 4;
            if (t == 1) {
                a.push_back(l[j]);
            } else if (t == 2) {
                b.push_back(l[j]);
            } else if (t == 3) {
                c.push_back(l[j]);
            }
        }
        if (a.size() == 0 || b.size() == 0 || c.size() == 0) {
            continue;
        }
        ll sum = 0;
        sum += (a.size() - 1) * 10;
        sum += (b.size() - 1) * 10;
        sum += (c.size() - 1) * 10;
        ll Asum = 0, Bsum = 0, Csum = 0;
        rep(j, a.size()) {
            Asum += a[j];
        }
        rep(j, b.size()) {
            Bsum += b[j];
        }
        rep(j, c.size()) {
            Csum += c[j];
        }
        sum += abs(Asum - A);
        sum += abs(Bsum - B);
        sum += abs(Csum - C);

        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
