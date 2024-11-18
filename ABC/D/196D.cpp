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

ll H, W, A, B;
ll ans = 0;

void dfs(ll i, ll j, ll rem, vvbool& used) {
    if (i == H) {
        if (rem == 0) {
            ans++;
        }
        return;
    }
    if (j == W) {
        dfs(i + 1, 0, rem, used);
        return;
    }
    if (used[i][j]) {
        dfs(i, j + 1, rem, used);
        return;
    }
    used[i][j] = true;
    if (j < W - 1 && !used[i][j + 1]) {
        used[i][j + 1] = true;
        dfs(i, j + 1, rem - 1, used);
        used[i][j + 1] = false;
    }
    if (i < H - 1 && !used[i + 1][j]) {
        used[i + 1][j] = true;
        dfs(i, j + 1, rem - 1, used);
        used[i + 1][j] = false;
    }
    used[i][j] = false;
    dfs(i, j + 1, rem, used);
}

int main() {
    cin >> H >> W >> A >> B;

    vvbool used(H, vbool(W, false));
    dfs(0, 0, A, used);
    cout << ans << endl;

    return 0;
}
