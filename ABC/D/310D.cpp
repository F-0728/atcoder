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
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << endl;}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << endl; }}

void dfs(ll idx, ll N, ll T, map<ll, vll>& mp, vvll& group, ll& ans) {
    if (idx == N) {
        ans++;
        return;
    }
    ll zeroCount = 0;
    rep(i, T) {
        if (group[i].empty()) {
            zeroCount++;
        }
    }
    rep(i, T) {
        if (zeroCount >= N - idx) {
            if (!group[i].empty()) continue;
        }
        bool ok = true;
        for (auto& g : group[i]) {
            if (find(mp[idx].begin(), mp[idx].end(), g) != mp[idx].end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            group[i].push_back(idx);
            dfs(idx + 1, N, T, mp, group, ans);
            group[i].pop_back();
        }
    }
}

int main() {
    ll N, T, M;
    cin >> N >> T >> M;

    ll ans = 0;
    map<ll, vll> mp;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (auto [k, v] : mp) {
        sort(v.begin(), v.end());
    }

    vvll group(T);

    dfs(0, N, T, mp, group, ans);

    ll f = 1;
    rep(i, T) {
        f *= i + 1;
    }

    cout << ans / f << endl;

    return 0;
}
