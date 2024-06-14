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
    vvll dist(N, vll(N, INF));
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist.at(a).at(b) = c;
    }
    rep(i, N) {
        dist.at(i).at(i) = 0;
    }
    ll ans = 0;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
                if (dist.at(i).at(j) != INF) {
                    ans += dist.at(i).at(j);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
