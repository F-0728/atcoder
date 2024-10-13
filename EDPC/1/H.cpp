#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S.at(i);

    vector<vector<mint>> dp(H, vector<mint>(W, 0));
    dp.at(0).at(0) = 1;
    rep(i, H) {
        rep(j, W) {
            if (S.at(i).at(j) == '#') continue;
            if (i > 0) dp.at(i).at(j) += dp.at(i - 1).at(j);
            if (j > 0) dp.at(i).at(j) += dp.at(i).at(j - 1);
        }
    }
    cout << dp.at(H - 1).at(W - 1).val() << endl;

    return 0;
}
