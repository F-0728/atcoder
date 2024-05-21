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
    vll A(N);
    rep(i, N) cin >> A[i];
    ll neg = 0;
    rep(i, N) if (A[i] < 0) neg++;

    ll ans = 0;
    rep(i, N) ans += abs(A[i]);

    if (neg % 2 == 0) {
        cout << ans << endl;
        return 0;
    }

    vll absA(N);
    rep(i, N) absA[i] = abs(A[i]);
    sort(absA.begin(), absA.end());
    cout << ans - 2 * absA[0] << endl;

    return 0;
}
