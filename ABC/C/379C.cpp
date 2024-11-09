#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vll X(M), A(M);
    rep(i, M) {
        cin >> X[i];
        X[i]--;
    }
    rep(i, M) {
        cin >> A[i];
    }
    vpll stones(M);
    rep(i, M) {
        stones[i] = {X[i], A[i]};
    }
    sort(stones.begin(), stones.end());

    ll ans = 0;
    ll nowIdx = 0;
    ll sum = 0;
    rep(i, M) {
        ll x = stones[i].first;
        ll a = stones[i].second;
        if (sum < x) {
            cout << -1 << endl;
            return 0;
        }
        ll over = sum - nowIdx - 1;
        ans += over * (x - nowIdx);
        ans -= (x - nowIdx) * (x - nowIdx - 1) / 2;
        nowIdx = x;
        sum += a;
    }
    if (sum != N) {
        cout << -1 << endl;
        return 0;
    }
    ans += (N - nowIdx) * (N - nowIdx - 1) / 2;

    cout << ans << endl;

    return 0;
}
