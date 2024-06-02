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
    ll K;
    cin >> K;
    ll ans = 0;
    vector<bool> mod(K, false);
    ll x = 7 % K;
    for (ll i = 1; i <= K; i++) {
        if (x == 0) {
            ans = i;
            break;
        }
        if (mod.at(x)) {
            cout << -1 << endl;
            return 0;
        }
        mod.at(x) = true;
        x = (x * 10 + 7) % K;
    }
    cout << ans << endl;

    return 0;
}
