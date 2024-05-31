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
    ll N, K;
    cin >> N >> K;
    mint ans = 0;
    for (ll i = K; i <= N + 1; i++) {
        ans += i * (2 * N - i + 1) / 2;
        ans -= i * (i - 1) / 2;
        ans += 1;
    }
    cout << ans.val() << endl;

    return 0;
}
