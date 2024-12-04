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
    vpll p(N);
    rep(i, N) {
        cin >> p[i].first >> p[i].second;
    }

    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    ll ans = 0;

    vvbool checked(N, vbool(N, false));
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            if (checked[i][j]) continue;
            ll dx = p[j].first - p[i].first;
            ll dy = p[j].second - p[i].second;
            checked[i][j] = true;
            checked[j][i] = true;
            ll count = 2;
            vll l;
            rep(k, N) {
                if (k == i || k == j) continue;
                if (checked[i][k]) continue;
                if (checked[j][k]) continue;
                ll dx2 = p[k].first - p[i].first;
                ll dy2 = p[k].second - p[i].second;
                if (dx * dy2 == dx2 * dy) {
                    checked[i][k] = true;
                    checked[k][i] = true;
                    checked[j][k] = true;
                    checked[k][j] = true;
                    l.push_back(k);
                }
            }
            ll s = l.size();
            rep(k, s) {
                for (ll m = k + 1; m < s; m++) {
                    checked[l[k]][l[m]] = true;
                    checked[l[m]][l[k]] = true;
                }
            }
            count += s;
            // cout << i << " " << j << " " << count << endl;
            if (count >= K) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
