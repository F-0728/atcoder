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
        string s;
        cin >> s;
        rep(j, W) {
            grid[i][j] = s[j];
        }
    }

    vvll leftStreak(H, vll(W, 0));
    vvll rightStreak(H, vll(W, 0));
    vvll upStreak(H, vll(W, 0));
    vvll downStreak(H, vll(W, 0));

    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') {
                leftStreak[i][j] = 0;
                rightStreak[i][j] = 0;
                upStreak[i][j] = 0;
                downStreak[i][j] = 0;
                continue;
            }
            if (j == 0) {
                leftStreak[i][j] = 1;
            }
            if (j > 0) {
                leftStreak[i][j] = leftStreak[i][j - 1] + 1;
            }
        }
    }
    for (ll i = H - 1; i >= 0; i--) {
        for (ll j = W - 1; j >= 0; j--) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (j == W - 1) {
                rightStreak[i][j] = 1;
            }
            if (j < W - 1) {
                rightStreak[i][j] = rightStreak[i][j + 1] + 1;
            }
        }
    }
    rep(j, W) {
        rep(i, H) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (i == 0) {
                upStreak[i][j] = 1;
            }
            if (i > 0) {
                upStreak[i][j] = upStreak[i - 1][j] + 1;
            }
        }
    }
    for (ll j = W - 1; j >= 0; j--) {
        for (ll i = H - 1; i >= 0; i--) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (i == H - 1) {
                downStreak[i][j] = 1;
            }
            if (i < H - 1) {
                downStreak[i][j] = downStreak[i + 1][j] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') {
                continue;
            }
            // if (ans < leftStreak[i][j] + rightStreak[i][j] + upStreak[i][j] + downStreak[i][j]) {
            //     cout << i << " " << j << endl;
            //     cout << "left: " << leftStreak[i][j] << endl;
            //     cout << "right: " << rightStreak[i][j] << endl;
            //     cout << "up: " << upStreak[i][j] << endl;
            //     cout << "down: " << downStreak[i][j] << endl;
            // }
            ans = max(ans, leftStreak[i][j] + rightStreak[i][j] + upStreak[i][j] + downStreak[i][j]);
        }
    }

    // rep(i, W) {
    //     cout << rightStreak[2][i] << " ";
    // }
    // cout << endl;

    cout << ans - 3 << endl;

    return 0;
}
