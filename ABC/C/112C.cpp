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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vvll height(N, vll(3));
    rep(i, N) {
        cin >> height[i][0] >> height[i][1] >> height[i][2];
    }

    rep(i, 101) {
        rep(j, 101) {
            vector<pair<ll, ll>> pos;
            ll h = -1;
            rep(k, N) {
                // if (i == 2 && j == 2) cout << "k: " << k << endl;
                if (height[k][2] > 0) {
                    ll tmp = height[k][2] + abs(i - height[k][0]) + abs(j - height[k][1]);
                    if (h == -1) {
                        h = tmp;
                    } else if (h != tmp) {
                        h = -2;
                        break;
                    }
                } else {
                    pos.push_back({height[k][0], height[k][1]});
                }
            }
            if (h >= 0) {
                rep(k, pos.size()) {
                    if (h - abs(i - pos[k].first) - abs(j - pos[k].second) > 0) {
                        h = -2;
                        break;
                    }
                }
            }
            // if (i == 2 && j == 2) cout << "h: " << h << endl;
            if (h >= 0) {
                cout << i << " " << j << " " << h << endl;
                return 0;
            }
        }
    }


    return 0;
}
