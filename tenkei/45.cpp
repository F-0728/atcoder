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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, K;
    cin >> N >> K;

    vpll points(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    vll dist(1 << N, -INF);
    dist[0] = 0;
    rep(i, 1 << N) {
        if (popcount((unsigned long long)i) == 1) {
            dist[i] = 0;
            continue;
        }
        rep(j, N) {
            rep(k, N) {
                if (j == k) continue;
                if (i & (1 << j) && i & (1 << k)) {
                    ll dx = points[j].first - points[k].first;
                    ll dy = points[j].second - points[k].second;
                    dist[i] = max(dist[i], dx * dx + dy * dy);
                }
            }
        }
    }

    vvll dp(K + 1, vll(1 << N, INF));
    dp[0][0] = 0;

    rep(i, K + 1) {
        if (i == 0) continue;
        rep(j, 1 << N) {
            if (j == 0) continue;
            for (ll k = j; k > 0; k = (k - 1) & j) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], dist[k]));
            }
        }
    }

    // rep(i, K + 1) {
    //     rep(j, 1 << N) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[K][(1 << N) - 1] << endl;

    return 0;
}
