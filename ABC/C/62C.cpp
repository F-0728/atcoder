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
    ll H, W;
    cin >> H >> W;

    ll ans = INF;
    rep(i, H - 1) {
        ll a = (i + 1) * W;
        ll b = (H - i - 1) * (W / 2);
        ll c = (H - i - 1) * (W - W / 2);
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    rep (i, W - 1) {
        ll a = (i + 1) * H;
        ll b = (W - i - 1) * (H / 2);
        ll c = (W - i - 1) * (H - H / 2);
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }

    if (H % 3 == 0 || W % 3 == 0) {
        ans = min(ans, 0LL);
    } else {
        ans = min(ans, min(H, W));
    }

    cout << ans << endl;

    return 0;
}
