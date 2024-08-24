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
    ll N, K;
    cin >> N >> K;

    vvll dp(60, vll(N + 1));
    rep(i, N + 1) {
        ll digitSum = 0;
        ll tmp = i;
        while (tmp > 0) {
            digitSum += tmp % 10;
            tmp /= 10;
        }
        dp[0][i] = i - digitSum;
    }
    for (ll i = 1; i < 60; i++) {
        rep(j, N + 1) { dp[i][j] = dp[i - 1][dp.at(i - 1)[j]]; }
    }

    rep(i, N + 1) {
        if (i == 0) continue;
        ll ans = i;
        rep(j, 30) {
            if (K & (1 << j)) {
                ans = dp[j][ans];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
