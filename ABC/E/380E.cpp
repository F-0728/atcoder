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

using S = long long;
using F = long long;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == INF ? x : f); }
F composition(F f, F g){ return (f == INF ? g : f); }
F id(){ return INF; }

S op2(S a, S b) { return std::max(a, b); }
S e2() { return -INF; }
S mapping2(F f, S x) { return (f == INF ? x : f); }
F composition2(F f, F g) { return (f == INF ? g : f); }
F id2() { return INF; }

S now;
bool gmin(S x) {
    return x <= now;
}

bool gmax(S x) {
    return x >= now;
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    lazy_segtree<S, op, e, F, mapping, composition, id> minseg(N);
    lazy_segtree<S, op2, e2, F, mapping2, composition2, id2> maxseg(N);

    rep(i, N) {
        minseg.set(i, i + 1);
        maxseg.set(i, i + 1);
    }
    vll count(N + 1, 0);
    rep(i, N) {
        count.at(i + 1) = 1;
    }

    rep(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, c;
            cin >> x >> c;
            x--;
            now = minseg.get(x);
            ll l1 = minseg.min_left<gmax>(x);
            ll r1 = minseg.max_right<gmax>(x);
            ll l2 = maxseg.min_left<gmin>(x);
            ll r2 = maxseg.max_right<gmin>(x);
            ll left = max(l1, l2);
            ll right = min(r1, r2);
            count.at(now) -= right - left;
            minseg.apply(left, right, c);
            maxseg.apply(left, right, c);
            count.at(c) += right - left;
        } else {
            ll c;
            cin >> c;
            cout << count.at(c) << endl;
        }
    }
    

    return 0;
}
