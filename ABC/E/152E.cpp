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

using mint = modint1000000007;
// using mint = modint998244353;
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

vpll prime_fact(ll x) {
    vpll res;
    ll i = 2;
    while (x > 1) {
        while (i * i <= x) {
            ll count = 0;
            while (x % i == 0) {
                x /= i;
                count++;
            }
            if (count > 0) {
                res.push_back({i, count});
            }
            i++;
        }
        if (x > 1) {
            res.push_back({x, 1});
            break;
        }
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vll fac(1e6 + 1, 0);
    rep(i, N) {
        vpll pf = prime_fact(A[i]);
        for (auto p : pf) {
            fac[p.first] = max(fac[p.first], p.second);
        }
    }

    mint lcm = 1;
    rep(i, 1e6 + 1) {
        if (fac[i] == 0) continue;
        lcm *= power(i, fac[i]);
    }

    mint ans = 0;
    rep(i, N) {
        ans += lcm / A[i];
    }

    cout << ans.val() << endl;

    return 0;
}