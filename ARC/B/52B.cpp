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
    ll N, Q;
    cin >> N >> Q;
    vvll corns(N, vll(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> corns[i][j];
        }
    }
    rep(i, Q) {
        ll A, B;
        cin >> A >> B;
        ld ans = 0;
        rep(j, N) {
            ll l = corns[j][0];
            ll r = corns[j][0] + corns[j][2];
            ld v = corns[j][1] * corns[j][1] * M_PI * corns[j][2] / 3;
            if (r <= A || B <= l) continue;
            if (A <= l && r <= B) {
                ans += v;
            } else if (A <= l && B <= r) {
                ld rem = r - B;
                ans += v - (corns[j][1] * (ld)rem / corns[j][2]) * (corns[j][1] * (ld)rem / corns[j][2]) * M_PI * rem / 3;
            } else if (r <= B && l <= A) {
                ld rem = r - A;
                ans += (corns[j][1] * (ld)rem / corns[j][2]) * (corns[j][1] * (ld)rem / corns[j][2]) * M_PI * rem / 3;
            } else {
                ld rem = r - A;
                ans += (corns[j][1] * (ld)rem / corns[j][2]) * (corns[j][1] * (ld)rem / corns[j][2]) * M_PI * rem / 3;
                rem = r - B;
                ans -= (corns[j][1] * (ld)rem / corns[j][2]) * (corns[j][1] * (ld)rem / corns[j][2]) * M_PI * rem / 3;
            }
            // cout << "j: " << j << endl;
            // cout << fixed << setprecision(10) << ans << endl;
        }
        cout << fixed << setprecision(10) << ans << endl;
    }


    return 0;
}
