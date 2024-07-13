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
template<typename T> void outv(const vector<T>& v){ for(const auto& e : v){ cout << e << " "; } cout << endl; }

int main() {
    ll N;
    cin >> N;
    vll A(N), B(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    rep(i, N) {
        cin >> B.at(i);
    }
    vector<vector<mint>> dp(N + 1, vector<mint>(3001, 0));
    vector<mint> cSum(3001, 1);
    dp.at(0).at(0) = 1;
    rep(i, N + 1) {
        if (i == 0) continue;
        rep(j, 3001) {
            if (j == 0) {
                cSum.at(j) = dp.at(i - 1).at(j);
            }
            else {
                cSum.at(j) = cSum.at(j - 1) + dp.at(i - 1).at(j);
            }
        }
        for (ll j = A.at(i - 1); j <= B.at(i - 1); j++) {
            dp.at(i).at(j) += cSum.at(j);
        }
    }
    mint ans = 0;
    rep(i, 3001) {
        ans += dp.at(N).at(i);
    }
    cout << ans.val() << endl;
}
