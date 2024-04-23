#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll A, B;
    cin >> A >> B;
    ll res = gcd(A, B);
    ll max = 1e18;

    if (A / res > max / B) {
        cout << "Large" << endl;
    } else {
        cout << A / res * B << endl;
    }
    return 0;
}
