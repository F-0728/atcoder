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
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll t, k;
        cin >> t >> k;
        k--;
        string to2K = "";
        ll tmp = k;
        while (tmp > 0) {
            to2K += to_string(tmp % 2);
            tmp /= 2;
        }
        reverse(to2K.begin(), to2K.end());
        ll start;
        if (t >= 60) {
            start = S[0] - 'A';
        } else {
            ll n = power(2, t);
            ll idx = k / n;
            start = S[idx] - 'A';
        }

        ll move = t % 3;
        rep(j, min((ll)to2K.size(), t)) {
            if (to2K[to2K.size() - 1 - j] == '1') {
                move++;
                move %= 3;
            }
        }

        start += move;
        start %= 3;

        char ans = 'A' + start;

        cout << ans << endl;
    }

    return 0;
}
