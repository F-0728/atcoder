#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll S;
    cin >> S;
    vector<mint> dp(2000 + 1, 1);
    dp.at(0) = 0;
    dp.at(1) = 0;
    dp.at(2) = 0;
    for (ll i = 4; i <= S; i++) {
        rep(j, i - 2) {
            dp.at(i) += dp.at(j);
        }
    }
    cout << dp.at(S).val() << endl;

    return 0;
}
