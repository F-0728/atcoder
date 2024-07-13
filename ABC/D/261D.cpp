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
    ll N, M;
    cin >> N >> M;
    vll X(N);
    rep(i, N) cin >> X.at(i);
    map<ll, ll> succession;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        succession[a] = b;
    }
    vvll dp(N + 1, vll(N + 1, -INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, N) {
            if (j == 0) {
                rep(k, N + 1) {
                    dp.at(i + 1).at(j) =
                        max(dp.at(i + 1).at(j), dp.at(i).at(k));
                }
            }
            if (succession.count(j + 1) > 0) {
                dp.at(i + 1).at(j + 1) =
                    max(dp.at(i).at(j) + X.at(i) + succession[j + 1],
                        dp.at(i + 1).at(j + 1));
            } else {
                dp.at(i + 1).at(j + 1) =
                    max(dp.at(i).at(j) + X.at(i), dp.at(i + 1).at(j + 1));
            }
        }
    }
    ll ans = -inf;
    rep(i, N + 1) {
        ans = max(ans, dp.at(N).at(i));
    }
    cout << ans << endl;

    return 0;
}
