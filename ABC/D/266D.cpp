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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vvll snuke(N + 1);
    snuke.at(0) = {0, 0, 0};
    rep(i, N) {
        ll t, x, a;
        cin >> t >> x >> a;
        snuke.at(i + 1) = {t, x, a};
    }
    vvll dp(N + 1, vll(5, -INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        ll elapsed = snuke.at(i + 1).at(0) - snuke.at(i).at(0);
        rep(j, 5) {
            if (j == snuke.at(i + 1).at(1)) {
                rep(k, 5) {
                    if (elapsed >= abs(j - k)) {
                        dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(k) + snuke.at(i + 1).at(2));
                    }
                }
            } else {
                rep(k, 5) {
                    if (elapsed >= abs(j - k)) {
                        dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(k));
                    }
                }
            }
        }
    }
    ll ans = -INF;
    rep(i, 5) {
        ans = max(ans, dp.at(N).at(i));
    }
    cout << ans << endl;

    return 0;
}
