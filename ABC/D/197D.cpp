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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N;
    double x1, y1, x2, y2;
    cin >> N >> x1 >> y1 >> x2 >> y2;
    double centerX = (x1 + x2) / 2;
    double centerY = (y1 + y2) / 2;
    x1 -= centerX;
    y1 -= centerY;
    double theta = 2 * M_PI / N;
    double ansX = x1 * cos(theta) + y1 * (-sin(theta));
    double ansY = x1 * sin(theta) + y1 * cos(theta);
    ansX += centerX;
    ansY += centerY;
    cout << fixed << setprecision(10) << ansX << " " << ansY << endl;

    return 0;
}
