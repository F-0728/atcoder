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
    vvll area(N, vll(3));
    ll Zsum = 0;
    rep(i, N) {
        rep(j, 3) {
            cin >> area.at(i).at(j);
            if (j == 2) {
                Zsum += area.at(i).at(j);
            }
        }
    }
    vll kuragae(N);
    rep(i, N) {
        kuragae.at(i) = max(0LL, (area.at(i).at(1) - area.at(i).at(0)) / 2 + 1);
    }
    vvll dp(N + 1, vll(Zsum + 1, INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, Zsum + 1) {
            dp.at(i + 1).at(j) = min(dp.at(i + 1).at(j), dp.at(i).at(j));
            if (j + area.at(i).at(2) <= Zsum) {
                dp.at(i + 1).at(j + area.at(i).at(2)) = min(dp.at(i + 1).at(j + area.at(i).at(2)), dp.at(i).at(j) + kuragae.at(i));
            }
        }
    }
    // rep(i, N + 1) {
    //     outv(dp.at(i));
    // }
    ll ans = INF;
    for (ll i = Zsum / 2 + 1; i <= Zsum; i++) {
        ans = min(ans, dp.at(N).at(i));
    }
    cout << ans << endl;



    return 0;
}
