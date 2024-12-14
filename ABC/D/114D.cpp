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

    vll divs(N + 1, 0);
    for (ll i = 1; i <= N; i++) {
        vpll pf = prime_fact(i);
        for (auto p : pf) {
            divs[p.first] += p.second;
        }
    }

    ll count2 = 0;
    ll count4 = 0;
    ll count14 = 0;
    ll count24 = 0;
    ll count74 = 0;
    rep(i, N + 1) {
        if (divs[i] >= 2) {
            count2++;
        }
        if (divs[i] >= 4) {
            count4++;
        }
        if (divs[i] >= 14) {
            count14++;
        }
        if (divs[i] >= 24) {
            count24++;
        }
        if (divs[i] >= 74) {
            count74++;
        }
    }

    ll ans = count4 * (count4 - 1) / 2 * (count2 - 2);
    ans += count14 * (count4 - 1);
    ans += count24 * (count2 - 1);
    ans += count74;

    cout << ans << endl;

    return 0;
}
