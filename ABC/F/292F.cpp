#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);

    ld l = A, r = 2 * A / sqrt(3);
    while (r - l > 1e-15) {
        ld mid = (l + r) / 2;
        ld angle = acosl(A / mid);
        // cout << fixed << setprecision(20) << angle / M_PI * 180 << endl;
        if (cosl(M_PI / 6 - angle) * mid <= B) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(20) << l << endl;

    return 0;
}
