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
    ll T;
    cin >> T;

    vll A(5);
    vll P(5);

    rep(i, T) {
        rep(j, 5) {
            cin >> A[j];
        }
        rep(j, 5) {
            cin >> P[j];
        }

        ll ans = INF;
        ll need = 2 * A[0] + A[1] - A[3] - 2 * A[4];
        if (need <= 0) {
            cout << 0 << endl;
            continue;
        }

        rep(j, 5) {
            ll cost = 0;
            ll rem = need - j;
            if (rem < 0) {
                break;
            }
            cost += P[3] * j;
            if (rem > 0) {
                ll k = (rem + 1) / 2;
                cost += P[4] * k;
            }
            ans = min(ans, cost);
        }
        rep(j, 4) {
            ll cost = 0;
            ll rem = need - 2 * j;
            if (rem < 0) {
                break;
            }
            cost += P[4] * j;
            if (rem > 0) {
                ll k = rem;
                cost += P[3] * k;
            }
            ans = min(ans, cost);
        }

        cout << ans << endl;
    }

    return 0;
}
