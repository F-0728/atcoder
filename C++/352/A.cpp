#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    if ((X-Z) * (Y-Z) < 0) {
        Yes;
    } else {
        No;
    }

    return 0;
}
