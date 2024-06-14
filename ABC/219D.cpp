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

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vpll obento(N);
    rep(i, N) { cin >> obento.at(i).first >> obento.at(i).second; }
    vector<vector<vector<ll>>> dp(N + 1, vvll(X + 1, vll(Y + 1, INF)));
    rep(i, N) {
        dp.at(i).at(0).at(0) = 0;
        rep(j, X + 1) {
            rep(k, Y + 1) {
                dp.at(i + 1).at(j).at(k) =
                    min(dp.at(i + 1).at(j).at(k), dp.at(i).at(j).at(k));
                ll xMax = min(X, j + obento.at(i).first);
                ll yMax = min(Y, k + obento.at(i).second);
                dp.at(i + 1).at(xMax).at(yMax) = min(
                    dp.at(i + 1).at(xMax).at(yMax), dp.at(i).at(j).at(k) + 1);
            }
        }
    }
    if (dp.at(N).at(X).at(Y) == INF) {
        cout << -1 << endl;
    } else {
        cout << dp.at(N).at(X).at(Y) << endl;
    }

    return 0;
}
