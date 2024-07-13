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
    ll N, M;
    cin >> N >> M;

    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return 0;
    }

    if (N == M) {
        mint ans = 1;
        for (ll i = 1; i <= N; i++) {
            ans *= i;
        }
        ans *= ans;
        ans *= 2;
        cout << ans.val() << endl;
        return 0;
    }

    mint ans = 1;
    for (ll i = 1; i <= N; i++) {
        ans *= i;
    }
    for (ll i = 1; i <= M; i++) {
        ans *= i;
    }
    cout << ans.val() << endl;

    return 0;
}
