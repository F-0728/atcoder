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
    vvll scores(N, vll(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> scores.at(i).at(j);
        }
    }
    vvll dp(3, vll(N, 0));
    rep(i, 3) {
        dp.at(i).at(0) = scores.at(0).at(i);
    }
    rep(i, N) {
        if (i == 0) continue;
        rep(j, 3) {
            rep(k, 3) {
                if (j == k) continue;
                dp.at(j).at(i) = max(dp.at(j).at(i), dp.at(k).at(i - 1) + scores.at(i).at(j));
            }
        }
    }
    ll ans = 0;
    rep(i, 3) {
        ans = max(ans, dp.at(i).at(N - 1));
    }
    cout << ans << endl;

    return 0;
}
