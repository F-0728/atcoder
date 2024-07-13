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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll d = 10;
    while (N / d > 0) {
        ans += N / d;
        d *= 5;
    }
    cout << ans << endl;

    return 0;
}
