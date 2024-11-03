#include <atcoder/all>
#include <chrono>
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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
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
    vpll points(N);
    rep(i, N) { cin >> points[i].first >> points[i].second; }

    vvld dist(1 << N, vld(N, INF));
    rep(i, N) { dist.at(0).at(i) = 0; }
    dist.at(1).at(0) = 0;
    rep(i, 1 << N) {
        if (i == 0) continue;
        rep(j, N) {
            rep(k, N) {
                if ((i >> k) & 1) continue;
                ld d = hypotl(points[j].first - points[k].first, points[j].second - points[k].second);
                dist.at(i | (1 << k)).at(k) = min(dist.at(i | (1 << k)).at(k), dist.at(i).at(j) + d);
            }
        }
    }

    ld ans = INF;
    rep(i, N) { 
        ld last = hypotl(points[i].first - points[0].first, points[i].second - points[0].second);
        ans = min(ans, dist.at((1 << N) - 1).at(i) + last);
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
