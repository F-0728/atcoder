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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }
    rep(i, N) { cin >> C[i]; }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(i, N) {
        ll j = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll k = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
        ans += j * (N - k);
    }
    cout << ans << endl;

    return 0;
}
