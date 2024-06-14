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
    ll N, K;
    cin >> N >> K;
    vll A(N + 1);
    rep(i, N) {
        ll a;
        cin >> a;
        A.at(i) = a;
    }
    A.at(N) = 0;
    sort(A.rbegin(), A.rend());
    ll ans = 0;
    rep(i, N) {
        ll diff = A.at(i) - A.at(i + 1);
        ll count = diff * (i + 1);
        if (count <= K) {
            ans += (A.at(i) + A.at(i + 1) + 1) * diff / 2 * (i + 1);
            K -= count;
        } else {
            ll x = K / (i + 1);
            ll y = K % (i + 1);
            ans += (A.at(i) + A.at(i) - x + 1) * x / 2 * (i + 1);
            ans += (A.at(i) - x) * y;
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
