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

int main() {
    string s, t;
    cin >> s >> t;

    ll N = s.size();
    ll M = t.size();

    vvll idx(26);
    rep(i, N) {
        idx[s[i] - 'a'].push_back(i);
    }

    ll ans = 0;
    ll now = -1;
    rep(i, M) {
        ll c = t[i] - 'a';
        if (idx[c].empty()) {
            cout << -1 << endl;
            return 0;
        }
        ll newIdx = lower_bound(idx[c].begin(), idx[c].end(), now + 1) - idx[c].begin();
        if (newIdx == idx[c].size()) {
            ans += N;
            now = idx[c][0];
        } else {
            now = idx[c][newIdx];
        }
    }

    cout << ans + now + 1 << endl;



    return 0;
}
