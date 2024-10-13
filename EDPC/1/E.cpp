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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, W;
    cin >> N >> W;
    vpll nimotsu(N);
    rep(i, N) {
        ll w, v;
        cin >> w >> v;
        nimotsu.at(i) = {w, v};
    }
    ll V = 0;
    rep(i, N) { V += nimotsu.at(i).second; }
    vvll dp(N + 1, vll(V + 1, INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, V + 1) {
            if (j - nimotsu.at(i).second >= 0) {
                dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j - nimotsu.at(i).second) + nimotsu.at(i).first);
            }
            dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j));
        }
    }
    ll ans = 0;
    rep(i, V + 1) {
        if (dp.at(N).at(i) <= W) {
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
