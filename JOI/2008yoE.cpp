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
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H, W;
    cin >> H >> W;
    vvll senbei(H, vll(W));
    rep(i, H) rep(j, W) cin >> senbei[i][j];

    ll ans = 0;
    rep(i, 1 << H) {
        vvll senbeiNow = senbei;
        vll ura(W, 0);
        rep(j, H) {
            rep(k, W) {
                if (i & (1 << j)) {
                    senbeiNow.at(j).at(k) = 1 - senbei.at(j).at(k);
                }
            }
        }
        rep(j, W) {
            rep(k, H) {
                if (senbeiNow.at(k).at(j) == 1) {
                    ura.at(j)++;
                }
            }
        }
        ll res = 0;
        rep(j, W) {
            res += max(ura.at(j), H - ura.at(j));
        }
        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}
