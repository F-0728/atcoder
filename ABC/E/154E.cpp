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
    string N;
    cin >> N;
    ll dig = N.size();
    ll K;
    cin >> K;

    ll ans = 0;
    if (K == 1) {
        ans += 9 * (dig - 1) + (N[0] - '0');
    }

    if (K == 2) {
        if (dig == 1) {
            cout << 0 << endl;
            return 0;
        }
        ans += (dig - 1) * 9 * (dig - 2) * 9 / 2;
        ans += (N[0] - '0' - 1) * (dig - 1) * 9;
        bool ok = false;
        rep(j, dig - 1) {
            if (ok) {
                ans += 9;
            } else {
                ans += N[j + 1] - '0';
            }
            if (N[j + 1] != '0') {
                ok = true;
            }
        }
    }

    if (K == 3) {
        if (dig <= 2) {
            cout << 0 << endl;
            return 0;
        }
        ans += (dig - 1) * 9 * (dig - 2) * 9 * (dig - 3) * 9 / 6;
        ans += (N[0] - '0' - 1) * 9 * (dig - 1) * (dig - 2) * 9 / 2;
        bool okj = false;
        bool okk = false;
        rep(j, dig - 2) {
            if (N[j + 1] == '0' && !okj) continue;
            for (ll k = j + 1; k < dig - 1; k++) {
                if (okj) {
                    ans += 9 * 9;
                } else if (okk) {
                    ans += (N[j + 1] - '0') * 9;
                } else {
                    ans += (N[j + 1] - '0' - 1) * 9;
                    ans += N[k + 1] - '0';
                }
                if (N[k + 1] != '0') {
                    okk = true;
                }
            }
            if (N[j + 1] != '0') {
                okj = true;
            }
            if (!okj) okk = false;
        }
    }

    cout << ans << endl;

    return 0;
}
