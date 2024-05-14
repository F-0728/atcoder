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

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> s[i][j];

    queue<vector<ll>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    q.push({0, 0, 1});
    ll ans = 1e8;
    while (!q.empty()) {
        vector<ll> p = q.front();
        // cout << p[0] << " " << p[1] << " " << p[2] << endl;
        q.pop();
        ll r = p[0];
        ll c = p[1];
        if (r >= H || c >= W || r < 0 || c < 0) continue;
        if (s[r][c] == '#') continue;
        if (visited[r][c]) continue;
        visited[r][c] = true;
        if (r == H - 1 && c == W - 1) {
            ans = min(ans, p[2]);
        }
        q.push({r + 1, c, p[2] + 1});
        q.push({r, c + 1, p[2] + 1});
        q.push({r - 1, c, p[2] + 1});
        q.push({r, c - 1, p[2] + 1});
    }

    ll countWhite = 0;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '.') countWhite++;
        }
    }
    if (ans == 1e8) {
        cout << -1 << endl;
        return 0;
    }
    cout << countWhite - ans << endl;
    return 0;
}
