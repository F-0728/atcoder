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
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    dsu d(200005);
    rep(i, N / 2) {
        if (A.at(i) != A.at(N - 1 - i)) {
            d.merge(A.at(i), A.at(N - 1 - i));
        }
    }
    ll ans = 0;
    vector<vector<int>> group = d.groups();
    rep(i, group.size()) {
        ans += group.at(i).size() - 1;
    }

    cout << ans << endl;
    return 0;
}
