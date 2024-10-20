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
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll N;
        cin >> N;
        mint ans = 0;

        mint tmp = 0;
        for (ll y = 2; y * y < N; y++) {
            ll z = N / y;
            tmp += (z - y) * (y - 1);
        }
        ans += tmp * 6;

        tmp = 0;
        for (ll y = 1; y * y < N; y++) {
            ll z = N / y;
            tmp += z - y;
        }
        ans += tmp * 3;

        tmp = 0;
        for (ll y = 2; y * y <= N; y++) {
            tmp += y - 1;
        }
        ans += tmp * 3;

        tmp = 0;
        for (ll y = 1; y * y <= N; y++) {
            tmp++;
        }
        ans += tmp;

        cout << ans.val() << endl;
    }

    return 0;
}
