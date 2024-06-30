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
    ll N, K, D;
    cin >> N >> K >> D;
    vll A(N);
    rep(i, N) { cin >> A.at(i); }
    vector<vvll> dp(N + 1, vvll(K + 1, vll(D, -INF)));
    dp.at(0).at(0).at(0) = 0;
    rep(i, N) {
        rep(j, K + 1) {
            if (i < j) continue;
            rep(k, D) {
                dp.at(i + 1).at(j).at(k) = dp.at(i).at(j).at(k);
            }
        }
        rep(j, K) {
            if (i < j) continue;
            rep(k, D) {

                ll nk = (k + A.at(i)) % D;
                dp.at(i + 1).at(j + 1).at(nk) = max(dp.at(i + 1).at(j + 1).at(nk), dp.at(i).at(j).at(k) + A.at(i));
            }
        }
        // cout << "i: " << i << endl;
        // rep(j, K + 1) {
        //     outv(dp.at(i + 1).at(j));
        // }
    }
    ll ans = dp.at(N).at(K).at(0);
    if (ans < 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
