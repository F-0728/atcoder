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

vector<ll> divisors(ll x) {
    vector<ll> divs;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

int main() {
    ll N;
    cin >> N;
    vll P(N);
    rep(i, N) cin >> P[i];
    vll Q(N);
    rep(i, N) cin >> Q[i];

    map<ll, ll> indexP;
    map<ll, ll> indexQ;

    rep(i, N) {
        indexP[P[i]] = i;
        indexQ[Q[i]] = i;
    }

    vpll p;

    for (ll i = 1; i <= N; i++) {
        vll divs = divisors(i);
        for (ll d : divs) {
            p.push_back({indexP[d], indexQ[i]});
        }
    }

    sort(p.begin(), p.end(), [](pll a, pll b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    vll lis(p.size(), INF);
    rep(i, p.size()) {
        *lower_bound(lis.begin(), lis.end(), p[i].second) = p[i].second;
    }

    ll ans = lower_bound(lis.begin(), lis.end(), INF) - lis.begin();

    cout << ans << endl;

    return 0;
}
