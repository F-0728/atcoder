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
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;
    if ((Sx + Sy) % 2 == 0) Sx += 1;
    ll ans = 0;
    ans += abs(Ty - Sy);
    if (Sx % 2 == 1 && Sy % 2 == 0) {
        if (Tx <= Sx) {
            if (Sx - Tx > abs(Ty - Sy) + 1) {
                ans += (Sx - Tx - abs(Ty - Sy)) / 2;
            }
        } else {
            if (Tx - Sx > abs(Ty - Sy))
                ans += (Tx - Sx - abs(Ty - Sy) + 1) / 2;
        }
    } else {
        if (Tx <= Sx) {
            if (Sx - Tx > abs(Ty - Sy) + 1) {
                ans += (Sx - Tx - abs(Ty - Sy)) / 2;
            }
        } else {
            if (Tx - Sx > abs(Ty - Sy))
                ans += (Tx - Sx - abs(Ty - Sy) + 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
