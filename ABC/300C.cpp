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
    ll N = min(H, W);

    vector<string> C(H);
    vector<pair<ll, ll>> cross;
    rep(i, H) {
        cin >> C[i];
        rep(j, W) {
            if (C[i][j] == '#') {
                cross.push_back(make_pair(i, j));
            }
        }
    }

    vector<ll> ans(N + 1, 0);
    rep(i, cross.size()) {
        ll h = cross[i].first;
        ll w = cross[i].second;
        ll count = 0;
        for(ll j = 1; j < N; j++) {
            if (h + j < H && w + j < W && h - j >= 0 && w - j >= 0) {
                if (C[h + j][w + j] == '#' && C[h - j][w - j] == '#' && C[h - j][w + j] == '#' && C[h + j][w - j] == '#') {
                    count++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        ans[count]++;
    }

    rep(i, N + 1) {
        if (i == 0) continue;
        cout << ans[i] << endl;
    }

     return 0;
}
