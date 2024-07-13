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
    vector<bool> lighted(N, false);
    rep(i, N) {
        cin >> A[i];
    }
    lighted[0] = true;
    ll current = 0;

    ll ans = 0;
    while (current != 1) {
        if (lighted[A[current]]) {
            cout << -1 << endl;
            return 0;
        }
        lighted[A[current]] = true;
        current = A[current] - 1;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
