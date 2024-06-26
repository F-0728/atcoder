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

ll calc(ll a, ll b) { return a * a * a + a * a * b + a * b * b + b * b * b; }
int main() {
    ll N;
    cin >> N;
    ll ans = INF;
    rep(i, 1e6 + 5) {
        ll left = 0;
        ll right = 1e6 + 5;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (calc(mid, i) >= N) {
                right = mid;
            } else {
                left = mid;
            }    
        }
        if (calc(right, i) >= N) {
            // if (calc(left, i) < 100) cout << i << " " << left << endl;
            ans = min(ans, calc(right, i));
        }
        if (calc(left, i) >= N) {
            // if (calc(left, i) < 100) cout << i << " " << left << endl;
            ans = min(ans, calc(left, i));
        }
    }
    cout << ans << endl;

    return 0;
}
