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
    ll N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;
    A--;
    B--;

    vvmint ans(N - 1, vmint(N - 1, 0));
    for (ll i = N - 2; i >= 0; i--) {
        for (ll j = N - 2; j >= 0; j--) {
            ll stepI = N - 1 - i;
            ll stepJ = N - 1 - j;
            if (i == N - 2) {
                ans[i][j] = 1;
                continue;
            }
            mint next = 0;
            for (ll p = i + 1; p <= i + P; p++) {
                for (ll q = j + 1; q <= j + Q; q++) {
                    if (p > N - 2) {
                        next += 1;
                    } else if (q > N - 2) {
                        next += 0;
                    } else {
                        next += ans[p][q];
                    }
                }
            }
            // cout << i << " " << j << " " << next.val() << endl;
            next /= P * Q;
            ans[i][j] = next;
        }
    }

    // rep(i, N - 1) {
    //     rep(j, N - 1) {
    //         cout << ans[i][j].val() << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans[A][B].val() << endl;

    return 0;
}
