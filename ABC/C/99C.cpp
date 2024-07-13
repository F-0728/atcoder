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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    ll ans = 1e9;
    rep(i, N + 1) {
        ll sum = 0;
        ll sixSum = i;
        while (sixSum > 0) {
            sum += sixSum % 6;
            sixSum /= 6;
        }
        ll nineSum = N - i;
        while (nineSum > 0) {
            sum += nineSum % 9;
            nineSum /= 9;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
