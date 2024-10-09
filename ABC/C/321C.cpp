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
    ll K;
    cin >> K;

    vll ans(1023);
    rep(i, 1 << 10) {
        if (i == 0) continue;
        vll bit(10);
        rep(j, 10) {
            if (i >> j & 1) {
                bit[j] = 1;
            }
        }
        ll num = 0;
        for (ll j = 9; j >= 0; j--) {
            if (bit[j]) {
                num *= 10;
                num += j;
            }
        }
        ans[i - 1] = num;
    }

    sort(ans.begin(), ans.end());

    // outv(ans);

    cout << ans[K] << endl;

    return 0;
}
