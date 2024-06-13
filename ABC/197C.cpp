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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    ll ans = INF;
    rep(i, 1 << N) {
        ll orSum = 0;
        ll xorSum = 0;
        rep(j, N) {
            orSum |= A.at(j);
            if (i >> j & 1) {
                xorSum ^= orSum;
                orSum = 0;
            }
        }
        xorSum ^= orSum;
        ans = min(ans, xorSum);
    }
    cout << ans << endl;

    return 0;
}
