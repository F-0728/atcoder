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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N);
    rep(i, N) cin >> A[i];

    vvll a;
    vll tmp;
    rep(i, N) {
        if (A[i] <= X && A[i] >= Y) {
            tmp.push_back(A[i]);
        } else {
            if (tmp.size() > 0) {
                a.push_back(tmp);
                tmp.clear();
            }
        }
    }
    if (tmp.size() > 0) {
        a.push_back(tmp);
    }

    ll ans = 0;
    for (auto& v : a) {
        ll n = v.size();
        ll l = 0, r = 0;
        ll countX = 0, countY = 0;
        while (r < n || l < n) {
            while (r < n && (countX <= 0 || countY <= 0)) {
                if (v[r] == X) countX++;
                if (v[r] == Y) countY++;
                r++;
            }
            if (countX > 0 && countY > 0) {
                // cout << l << " " << r << endl;
                ans += n - r + 1;
            }
            if (v[l] == X) countX--;
            if (v[l] == Y) countY--;
            l++;
            if (l > r) r = l;
        }
    }

    cout << ans << endl;

    return 0;
}
