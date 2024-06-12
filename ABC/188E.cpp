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
    ll N, M;
    cin >> N >> M;
    vll price(N);
    rep (i, N) {
        ll A;
        cin >> A;
        price.at(i) = A;
    }
    vpll path(M);
    rep (i, M) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        path.at(i) = make_pair(A, B);
    }
    sort(path.begin(), path.end());
    vll dp(N, INF);
    rep (i, M) {
        ll A = path.at(i).first;
        ll B = path.at(i).second;
        dp.at(B) = min(dp.at(B), min(dp.at(A), price.at(A)));
    }
    ll ans = -INF;
    rep (i, N) {
        ans = max(ans, price.at(i) - dp.at(i));
    }
    cout << ans << endl;

    return 0;
}
