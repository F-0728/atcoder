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
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << endl;
}
template <typename T>
void outvv(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        outv(v);
    }
}
void outvvmint(const vector<vector<mint>>& vv) {
    for (const auto& v : vv) {
        outvmint(v);
    }
}
template <typename T>
void outvp(const vector<pair<T, T>>& vp) {
    for (const auto& p : vp) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    ll N;
    cin >> N;
    vpll t(N);
    rep(i, N) { cin >> t[i].first >> t[i].second; }

    ll ans1 = 1, ans2 = 1;
    rep(i, N) {
        ll q1 = (ans1 - 1) / t[i].first + 1;
        ll q2 = (ans2 - 1) / t[i].second + 1;
        ans1 = t[i].first * max(q1, q2);
        ans2 = t[i].second * max(q1, q2);
        // cout << "ans1: " << ans1 << " ans2: " << ans2 << endl;
    }

    cout << ans1 + ans2 << endl;

    return 0;
}
