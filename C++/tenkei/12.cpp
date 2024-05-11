#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll H, W, Q;
    cin >> H >> W >> Q;
    dsu d(H * W);
    vector<bool> painted(H * W, false);
    rep (i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll r, c;
            cin >> r >> c;
            r--; c--;
            painted[r * W + c] = true;
            if (r > 0 && painted[(r - 1) * W + c]) {
                d.merge(r * W + c, (r - 1) * W + c);
            }
            if (r < H - 1 && painted[(r + 1) * W + c]) {
                d.merge(r * W + c, (r + 1) * W + c);
            }
            if (c > 0 && painted[r * W + c - 1]) {
                d.merge(r * W + c, r * W + c - 1);
            }
            if (c < W - 1 && painted[r * W + c + 1]) {
                d.merge(r * W + c, r * W + c + 1);
            }
        } else {
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            if (!painted[ra * W + ca] || !painted[rb * W + cb]) {
                No;
                continue;
            }
            if (d.same(ra * W + ca, rb * W + cb)) {
                Yes;
            } else {
                No;
            }
        }
    }


    return 0;
}
