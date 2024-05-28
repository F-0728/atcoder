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
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    rep(i, H) {
        string S;
        cin >> S;
        rep(j, W) {
            grid[i][j] = S[j];
        }
    }
    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (grid.at(i).at(j) == '#') continue;
            queue<pair<ll, ll>> q;
            vvll dist(H, vll(W, -1));
            q.push({i, j});
            vpll d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            dist.at(i).at(j) = 0;
            while (!q.empty()) {
                pair<ll, ll> p = q.front();
                q.pop();
                for (pair<ll, ll> dir : d) {
                    ll x = p.first + dir.first;
                    ll y = p.second + dir.second;
                    if (x < 0 || x >= H || y < 0 || y >= W) continue;
                    if (grid.at(x).at(y) == '#') continue;
                    if (dist.at(x).at(y) != -1) continue;
                    dist.at(x).at(y) = dist.at(p.first).at(p.second) + 1;
                    q.push({x, y});
                }
            }
            rep(k, H) {
                rep(l, W) {
                    if (dist.at(k).at(l) != -1) {
                        ans = max(ans, dist.at(k).at(l));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
