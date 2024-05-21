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
    vector<ll> A;
    cin >> N;
    rep(i, N) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    vll cmlForward(N, A[0]);
    vll cmlBackward(N, A[N - 1]);

    rep(i, N - 1) {
        cmlForward[i + 1] = gcd(cmlForward[i], A[i + 1]);
    }
    for (ll i = N - 1; i > 0; i--) {
        cmlBackward[i - 1] = gcd(cmlBackward[i], A[i - 1]);
    }

    ll ans = 0;
    rep(i, N) {
        if (i == 0) {
            ans = max(ans, cmlBackward[i + 1]);
        } else if (i == N - 1) {
            ans = max(ans, cmlForward[i - 1]);
        } else {
            ans = max(ans, gcd(cmlForward[i - 1], cmlBackward[i + 1]));
        }
    }
    cout << ans << endl;

    return 0;
}
