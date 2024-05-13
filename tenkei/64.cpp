#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> height(N, 0);
    vector<ll> dif(N, 0);
    ll ans = 0;
    rep(i, N) {
        ll A;
        cin >> A;
        height[i] = A;
        if (i != 0) {
            dif[i] = A - height[i - 1];
            ans += abs(dif[i]);
        }
    }

    rep(i, Q) {
        ll L, R, V;
        cin >> L >> R >> V;
        ll Lprev = dif[L - 1];
        ll Rprev = dif[R];
        if (L > 1) {
            ans -= abs(Lprev);
            dif[L - 1] += V;
            ans += abs(dif[L - 1]);
        }
        if (R < N) {
            ans -= abs(Rprev);
            dif[R] -= V;
            ans += abs(dif[R]);
        }
        cout << ans << endl;
    }

    return 0;
}
