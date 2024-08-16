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
    ll N;
    cin >> N;
    vpll point(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        point.at(i) = make_pair(x, y);
    }

    double ans = INF;
    vector<vector<double>> dp(1 << N, vector<double>(N, INF));
    rep(i, N) {
        double res = INF;
        rep(i2, 1 << N) {
            rep(j2, N) {
                dp.at(i2).at(j2) = INF;
            }
        }
        dp.at(1 << i).at(i) = 0;
        rep(l, (1 << N) - 1) {
            rep(j, N) {
                if (dp.at(l).at(j) == INF) continue;
                rep(k, N) {
                    if (l & (1 << k)) continue;
                    ll distX = point.at(j).first - point.at(k).first;
                    ll distY = point.at(j).second - point.at(k).second;
                    ll dist = distX * distX + distY * distY;
                    dp.at(l | (1 << k)).at(k) =
                        min(dp.at(l | (1 << k)).at(k), dp.at(l).at(j) + sqrt(dist));
                }
            }
        }
        rep(j, N) {
            ll distX = point.at(i).first - point.at(j).first;
            ll distY = point.at(i).second - point.at(j).second;
            ll dist = distX * distX + distY * distY;
            res = min(res, dp.at((1 << N) - 1).at(j) + sqrt(dist));
        }
        ans = min(ans, res);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
