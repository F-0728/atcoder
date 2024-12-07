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

struct S{
    mint value;
    int size;
};
using F = mint;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    ll N, K;
    cin >> N >> K;
    vpll LR(K);
    rep(i, K) {
        ll L, R;
        cin >> L >> R;
        LR[i] = {L, R};
    }
    sort(LR.begin(), LR.end());

    lazy_segtree<S, op, e, F, mapping, composition, id> dp(N);
    dp.set(0, {1, 1});
    rep(i, N - 1) {
        dp.set(i + 1, {0, 1});
    }
    rep(i, N - 1) {
        rep(j, K) {
            ll l = i + LR[j].first;
            if (l >= N) break;
            ll r = min(N, i + LR[j].second + 1);
            mint now = dp.get(i).value;
            // cout << l << " " << r << " " << now << endl;
            dp.apply(l, r, now);
        }
    }

    cout << dp.prod(N - 1, N).value.val() << endl;

    return 0;
}
