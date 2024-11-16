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

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vpll onestreak;
    ll idx = 0;
    ll prev = -1;
    ll streak = 0;
    rep(i, N) {
        if (S.at(i) == '1') {
            if (prev != -1) {
                streak++;
            } else {
                prev = i;
                streak = 1;
            }
        } else {
            if (prev != -1) {
                onestreak.push_back({prev, prev + streak});
                prev = -1;
            }
        }
    }
    if (prev != -1) {
        onestreak.push_back({prev, prev + streak});
    }

    ll start = onestreak.at(K - 1).first;
    ll end = onestreak.at(K - 1).second;
    ll endB = onestreak.at(K - 2).second;
    rep(i, endB) {
        cout << S.at(i);
    }
    for (ll i = start; i < end; i++) {
        cout << S.at(i);
    }
    for (ll i = endB; i < start; i++) {
        cout << S.at(i);
    }
    for (ll i = end; i < N; i++) {
        cout << S.at(i);
    }
    cout << endl;

    return 0;
}
