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
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vvll dp(N + 1, vll(M + 1, -INF));
    dp.at(0).at(0) = 0;
    rep(i, N) {
        rep(j, M + 1) {
            if (j == 0) {
                if (i < N - M) dp.at(i + 1).at(j) = 0;
            } else {
                dp.at(i + 1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j - 1) + A.at(i) * j);
            }
        }
    }
    cout << dp.at(N).at(M) << endl;

    return 0;
}
