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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid.at(i);
    ll ans = 0;
    rep(i, H - 1) {
        rep(j, W - 1) {
            ll cnt = 0;
            if (grid.at(i).at(j) == '#') cnt++;
            if (grid.at(i).at(j + 1) == '#') cnt++;
            if (grid.at(i + 1).at(j) == '#') cnt++;
            if (grid.at(i + 1).at(j + 1) == '#') cnt++;
            if (cnt == 1 || cnt == 3) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
