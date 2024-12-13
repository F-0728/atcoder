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
    ll N, M;
    cin >> N >> M;
    vvll cakes(N);
    rep(i, N) {
        ll x, y, z;
        cin >> x >> y >> z;
        cakes[i] = {x, y, z};
    }

    ll ans = -INF;
    rep(i, 2) {
        rep(j, 2) {
            rep(k, 2) {
                vll res;
                rep(idx, N) {
                    ll score = 0;
                    if (i % 2 == 0) {
                        score += cakes[idx][0];
                    } else {
                        score -= cakes[idx][0];
                    }
                    if (j % 2 == 0) {
                        score += cakes[idx][1];
                    } else {
                        score -= cakes[idx][1];
                    }
                    if (k % 2 == 0) {
                        score += cakes[idx][2];
                    } else {
                        score -= cakes[idx][2];
                    }
                    res.push_back(score);
                }
                sort(res.rbegin(), res.rend());
                ll sum = 0;
                rep(l, M) {
                    sum += res[l];
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
