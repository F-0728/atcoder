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
    vector<vector<ll>> P(H, vector<ll>(W));

    rep(i, H) {
        rep(j, W) {
            ll a;
            cin >> a;
            P[i][j] = a;
        }
    }

    vector<vector<ll>> bitSearch;
    rep(i, 1 << H) {
        vector<ll> S;
        rep(j, H) {
            if (i & (1 << j)) {
                S.push_back(j);
            }
        }
        bitSearch.push_back(S);
    }

    ll ans = 1;
    rep(i, bitSearch.size()) {
        vector<ll> Rows = bitSearch[i];
        ll rowCount = Rows.size();
        vector<ll> count(H * W, 0);
        rep(j, W) {
            rep(k, rowCount) {
                if (rowCount == 1) {
                    count[P[Rows[k]][j] - 1]++;
                    continue;
                }
                if (k == 0) {
                    continue;
                }
                if (P[Rows[k]][j] != P[Rows[k - 1]][j]) {
                    break;
                }
                if (k == rowCount - 1) {
                    count[P[Rows[k]][j] - 1]++;
                }
            }
        }
        ll maxCurrent = 0;
        rep(j, H * W) {
            maxCurrent = max(maxCurrent, count[j]);
        }
        ans = max(ans, maxCurrent * rowCount);
    }

    cout << ans << endl;

    return 0;
}
