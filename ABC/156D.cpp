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

mint powMod(mint x, ll y) {
    mint res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    mint ans = powMod(2, N);
    ans -= 1;

    vector<mint> nCx(B + 1);
    nCx.at(0) = 1;
    rep(i, B) {
        nCx.at(i + 1) = nCx.at(i) * (N - i) / (i + 1);
    }

    ans -= nCx.at(A);
    ans -= nCx.at(B);
    cout << ans.val() << endl;

    return 0;
}
