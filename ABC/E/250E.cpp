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

int main() {
    ll N;
    cin >> N;
    vll a(N);
    rep(i, N) {
        cin >> a[i];
    }
    vll b(N);
    rep(i, N) {
        cin >> b[i];
    }

    map<ll, ll> hash;
    set<ll> used;
    rep(i, N) {
        if (hash.count(a[i])) continue;
        ll h = rand() / 2 + 1;
        while (used.count(h)) {
            h = rand() / 2 + 1;
        }
        hash[a[i]] = h;
    }
    rep(i, N) {
        if (hash.count(b[i])) continue;
        ll h = rand() / 2 + 1;
        while (used.count(h)) {
            h = rand() / 2 + 1;
        }
        hash[b[i]] = h;
    }

    set<ll> countA, countB;
    vll ca(N), cb(N);
    ca[0] = hash[a[0]];
    cb[0] = hash[b[0]];
    countA.insert(hash[a[0]]);
    countB.insert(hash[b[0]]);
    rep(i, N - 1) {
        if (countA.count(hash[a[i + 1]])) {
            ca[i + 1] = ca[i];
        } else {
            ca[i + 1] = ca[i] ^ hash[a[i + 1]];
            countA.insert(hash[a[i + 1]]);
        }
        if (countB.count(hash[b[i + 1]])) {
            cb[i + 1] = cb[i];
        } else {
            cb[i + 1] = cb[i] ^ hash[b[i + 1]];
            countB.insert(hash[b[i + 1]]);
        }
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        if (ca[A] == cb[B]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

    return 0;
}
