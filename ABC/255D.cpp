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
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> sum(N);
    rep(i, N) { cin >> A[i]; }
    sort(A.begin(), A.end());
    sum[0] = A[0];
    rep(i, N - 1) { sum[i + 1] = sum[i] + A[i + 1]; }

    rep(i, Q) {
        ll X;
        cin >> X;
        ll ans = 0;
        ll index = lower_bound(A.begin(), A.end(), X) - A.begin();
        if (index == 0) {
            ans = sum[N - 1] - N * X;
        } else {
            ans += sum[N - 1] - sum[index - 1] - (N - index) * X;
            ans += abs(sum[index - 1] - index * X);
        }
        cout << ans << endl;
    }

    return 0;
}
