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
    ll N, K, Q;
    cin >> N >> K >> Q;
    vll A(N, 0);

    ll ans = 0;
    set<ll> s;
    map<ll, ll> count;
    s.insert(0);
    count[0] = K;

    set<ll> s2;
    map<ll, ll> count2;
    s2.insert(0);
    count2[0] = N - K;

    ll size = K, size2 = N - K;

    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        x--;

        if (s2.find(A[x]) != s2.end()) {
            count2[A[x]]--;
            if (count2[A[x]] == 0) {
                s2.erase(A[x]);
            }
            size2--;
        } else {
            count[A[x]]--;
            if (count[A[x]] == 0) {
                s.erase(A[x]);
            }
            size--;
            ans -= A[x];
        }

        A[x] = y;
        if (s2.empty()) {
            if (y > *s.begin()) {
                count[y]++;
                s.insert(y);
                size++;
                ans += y;
            } else {
                count2[y]++;
                s2.insert(y);
                size2++;
            }
        } else {
            if (*s2.rbegin() >= y) {
                count2[y]++;
                s2.insert(y);
                size2++;
            } else {
                count[y]++;
                s.insert(y);
                size++;
                ans += y;
            }
        }

        if (size < K) {
            ll a = *s2.rbegin();
            count2[a]--;
            if (count2[a] == 0) {
                s2.erase(a);
            }
            size2--;
            ans += a;
            count[a]++;
            s.insert(a);
            size++;
        }
        if (size > K) {
            ll a = *s.begin();
            count[a]--;
            if (count[a] == 0) {
                s.erase(a);
            }
            size--;
            ans -= a;
            count2[a]++;
            s2.insert(a);
            size2++;
        }
        cout << ans << endl;
    }

    return 0;
}
