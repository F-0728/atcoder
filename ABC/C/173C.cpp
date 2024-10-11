#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H, W, K;
    cin >> H >> W >> K;

    vector<string> c(H);
    rep(i, H) cin >> c[i];

    ll ans = 0;
    rep(i, 1 << H) {
        rep(j, 1 << W) {
            ll blackCount = 0;
            rep(h, H) {
                rep(w, W) {
                    if (i & (1 << h)) {
                        if (j & (1 << w)) {
                            if (c[h][w] == '#') {
                                blackCount++;
                            }
                        }
                    }
                }
            }
            if (blackCount == K) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
