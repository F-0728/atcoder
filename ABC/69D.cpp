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
    ll H, W, N;
    cin >> H >> W >> N;
    vll a(N);
    rep(i, N) cin >> a[i];
    vll b;
    rep(i, N) rep(j, a[i]) b.push_back(i+1);
    vvll ans(H, vll(W));
    rep(i, H) {
        rep(j, W) {
            if (i % 2 == 0) {
                ans[i][j] = b[i*W+j];
            } else {
                ans[i][W-j-1] = b[i*W+j];
            }
        }
    }
    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j];
            if (j != W-1) cout << " ";
        }
        cout << endl;
    }



    return 0;
}
