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
    vvll edges(N, vll(N, -INF));
    rep(i, N - 1) {
        for (ll j = i + 1; j < N; j++) {
            ll d;
            cin >> d;
            edges.at(i).at(j) = d;
            edges.at(j).at(i) = d;
        }
    }
    vll dp(1 << N, -INF);
    dp.at(0) = 0;
    rep(i, 1 << N) {
        rep(j, N) {
            if ((i >> j) & 1) continue;
            rep(k, N) {
                if (j == k) continue;
                if ((i >> k) & 1) continue;
                dp.at(i | (1 << j) | (1 << k)) = max(dp.at(i | (1 << j) | (1 << k)), dp.at(i) + edges.at(j).at(k));
            }
        }
    }
    if (!(N & 1)) {
        cout << dp.at((1 << N) - 1) << endl;
    } else {
        ll ans = -INF;
        ll minus = 1;
        rep(i, N) {
            ans = max(ans, dp.at((1 << N) - 1 - minus));
            minus *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}
