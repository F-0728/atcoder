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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    auto next_magnet = [&](ll i, ll j) {
        for (auto d : dir) {
            ll ni = i + d.first;
            ll nj = j + d.second;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] == '#') return true;
        }
        return false;
    };

    vvll count(H, vll(W, -1));
    ll c = 0;

    function<void(ll, ll, ll)> dfs = [&](ll s, ll i, ll j) {
        // cout << i << " " << j << endl;
        if (count[i][j] == s) return;
        c++;
        count[i][j] = s;
        if (next_magnet(i, j)) return;
        for (auto d : dir) {
            ll ni = i + d.first;
            ll nj = j + d.second;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            dfs(s, ni, nj);
        }
    };

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            if (count[i][j] != -1) continue;
            c = 0;
            dfs(i * W + j, i, j);
            ans = max(ans, c);
        }
    }

    cout << ans << endl;

    return 0;
}
