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
    vvll chem(N, vll(N));
    rep(i, N) rep(j, N) cin >> chem.at(i).at(j);
    vector<vector<mint>> dp(N + 1, vector<mint>((1 << N) + 1, 0));
    dp.at(0).at(0) = 1;
    rep(j, 1 << N) {
        ll count = -1;
        rep(k, N) {
            if (j >> k & 1) count++;
        }
        rep(k, N) {
            if (j >> k & 1) {
                if (chem.at(count).at(k)) {
                    dp.at(count + 1).at(j) += dp.at(count).at(j ^ 1 << k);
                }
            }
        }
    }
    cout << dp.at(N).at((1 << N) - 1).val() << endl;

    return 0;
}
