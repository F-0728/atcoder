#include <atcoder/all>
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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

ll ans;
ll K;
vector<vector<bool>> visited;
void dfs(ll H, ll W, vector<string>& S, vll v, vector<vector<bool>>& visited) {
    ll i = v.at(0);
    ll j = v.at(1);
    ll d = v.at(2);
    if (i < 0 || i >= H || j < 0 || j >= W) {
        return;
    }
    if (S.at(i).at(j) == '#') {
        return;
    }
    if (visited.at(i).at(j)) {
        return;
    }
    if (d == K) {
        // cout << "i: " << i << " j: " << j << " d: " << d << endl;
        ans++;
        return;
    }
    visited.at(i).at(j) = true;
    rep(k, 4) {
        ll ni = i + dir.at(k).first;
        ll nj = j + dir.at(k).second;
        vll nv = {ni, nj, d + 1};
        dfs(H, W, S, nv, visited);
    }
    visited.at(i).at(j) = false;
}

int main() {
    ll H, W;
    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    visited.resize(H, vector<bool>(W, false));

    ans = 0;
    rep(i, H) {
        rep(j, W) {
            vll start = {i, j, 0};
            dfs(H, W, S, start, visited);
        }
    }

    cout << ans << endl;

    return 0;
}
