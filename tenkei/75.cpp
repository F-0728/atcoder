#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;

    ll i = 2;
    ll f = 0;
    while (N > 1) {
        while (i * i <= N) {
            if (N % i == 0) {
                f++;
                N /= i;
            } else {
                i++;
            }
        }
        if (N > 1) {
            f++;
            N /= N;
        }
    }
    if (f == 0) {
        cout << 0 << endl;
        return 0;
    }
    double ans = log2(f);
    cout << ceil(ans) << endl;

    return 0;
}
