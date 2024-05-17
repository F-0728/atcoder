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
    ll H, W;
    cin >> H >> W;
    vvll A(H, vll(W));
    rep(i, H) {
        rep(j, W) {
            cin >> A[i][j];
        }
    }

    vector<pair<pair<ll, ll>, pair<ll, ll>>> ans;
    rep(i, H) {
        rep(j, W-1) {
            if (A[i][j] % 2 == 1) {
                ans.push_back({{i+1, j+1}, {i+1, j+2}});
                A[i][j]--;
                A[i][j+1]++;
            }
        }
    }
    rep(i, H-1) {
        if (A[i][W-1] % 2 == 1) {
            ans.push_back({{i+1, W}, {i+2, W}});
            A[i][W-1]--;
            A[i+1][W-1]++;
        }
    }
    ll N = ans.size();
    cout << N << endl;
    rep(i, N) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
    }

    return 0;
}
