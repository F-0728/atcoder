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
    ll V, T, S, D;
    cin >> V >> T >> S >> D;

    ll start, end;
    start = V * T;
    end = V * S;

    if (D >= start && D <= end) {
        No;
    } else {
        Yes;
    }

    return 0;
}
