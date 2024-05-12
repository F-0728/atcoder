#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vector<vector<char>> c(10, vector<char>(10));
vector<pair<ll, ll>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<bool>> visited(10, vector<bool>(10));
ll H, W;

ll dfs(ll R, ll C, ll nextR, ll nextC) {
    if (nextR == R && nextC == C && visited[R][C]) return 0;
    visited[nextR][nextC] = true;

    ll maxLoop = -100;
    for (pair<ll, ll> d : dir) {
        ll newR = nextR + d.first;
        ll newC = nextC + d.second;
        if (newR < 0 || newR >= H || newC < 0 || newC >= W) continue;
        if (c[newR][newC] == '#') continue;
        if (visited[newR][newC]) {
            if (newR != R || newC != C) continue;
        }
        ll loop = dfs(R, C, newR, newC);
        maxLoop = max(maxLoop, loop + 1);
    }
    visited[nextR][nextC] = false;
    return maxLoop;
}

int main() {
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, H) {
        string str;
        cin >> str;
        rep(j, W) { c[i][j] = str[j]; }
    }

    ll ans = -1;

    rep(i, H) {
        rep(j, W) {
            if (c[i][j] == '#') continue;
            ll maxLoop = dfs(i, j, i, j);
            ans = max(ans, maxLoop);
        }
    }

    if (ans < 3) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
