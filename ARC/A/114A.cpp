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
    ll N;
    cin >> N;
    vll X(N);
    rep(i, N) cin >> X[i];

    vll factors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    vll y;
    rep(i, 1 << 15) {
        ll tmp = 1;
        rep(j, 15) {
            if (i >> j & 1) {
                tmp *= factors[j];
            }
        }
        y.push_back(tmp);
    }
    sort(y.begin(), y.end());
    for (ll Y : y) {
        bool ok = true;
        for (ll x : X) {
            if (gcd(x, Y) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << Y << endl;
            return 0;
        }
    }

    return 0;
}
