#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N);
    rep(i, N) {
        rep(j, 6) {
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    ll ans = 1;
    rep(i, N) {
        ll sum = 0;
        rep(j, 6) {
            sum += A[i][j];
        }
        ans *= sum;
        ans %= 1000000007;
    }
    cout << ans << endl;

    return 0;
}
