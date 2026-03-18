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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) { iota(idx.begin(), idx.end(), 0); sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; }); }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << "\n";}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << "\n";}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << "\n"; }}

vector<bool> furui(ll n) {
    vector<bool> res(n + 1, true);
    res[0] = false;
    res[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (res[i]) {
            for (ll j = 2 * i; j <= n; j += i) {
                res[j] = false;
            }
        }
    }
    return res;
}

ll powMod(ll x, ll y, ll MOD) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

vpll prime_fact(ll x, const vll& ps) {
    vpll res;
    ll idx = 0;
    while (x > 1 && idx < ps.size()) {
        while (ps[idx] * ps[idx] <= x) {
            ll count = 0;
            while (x % ps[idx] == 0) {
                x /= ps[idx];
                count++;
            }
            if (count > 0) {
                res.push_back({ps[idx], count});
            }
            idx++;
        }
        if (x > 1) {
            res.push_back({x, 1});
            break;
        }
    }
    return res;
}

int main() {
    vbool isPrime = furui(10'000'000);
    vll primes;
    rep(i, isPrime.size()) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        vll A(N);
        rep(i, N) cin >> A[i];

        vector<vpll> pfA(N);
        rep(i, N) {
            pfA[i] = prime_fact(A[i], primes);
        }
        
        map<ll, vll> mp;
        rep(i, N) {
            for (auto [p, e] : pfA[i]) {
                mp[p].push_back(e);
            }
        }
        for (auto& [p, v] : mp) {
            sort(v.rbegin(), v.rend());
        }

        mint ans = 1;
        for (auto [p, v] : mp) {
            ans *= powMod(p, v[0], mint::mod());
        }

        rep(i, N) {
            mint res = ans;
            for (auto [p, e] : pfA[i]) {
                if (e == mp[p][0]) {
                    if (mp[p].size() == 1) res /= powMod(p, e, mint::mod());
                    else res /= powMod(p, mp[p][0] - mp[p][1], mint::mod());
                }
            }
            cout << res.val() << " ";
        }
        cout << "\n";

    }

    return 0;
}
