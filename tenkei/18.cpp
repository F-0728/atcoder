#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    double T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    rep(i, Q) {
        double E;
        double y, z;
        cin >> E;
        y = -sin(E / T * M_PI * 2) * L / 2.0;
        z = -cos(E / T * M_PI * 2) * L / 2.0 + L / 2.0;
        double ans = atan2(z, sqrt(X * X + (Y - y) * (Y - y))) * 180 / M_PI;
        cout << setprecision(15) << ans << endl;
    }

    return 0;
}
