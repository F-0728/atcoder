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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vpll bags(N);
    rep(i, N) {
        ll W, V;
        cin >> W >> V;
        bags.at(i) = {V, W};
    }
    vll boxes(M);
    rep(i, M) { cin >> boxes.at(i); }
    sort(bags.begin(), bags.end(), greater<pair<ll, ll>>());
    rep(i, Q) {
        ll L, R;
        cin >> L >> R;
        vll available;
        rep(j, M) {
            if (j < L - 1 || j > R - 1) {
                available.push_back(boxes.at(j));
            }
        }
        sort(available.begin(), available.end());
        ll ans = 0;
        for (pair<ll, ll> b : bags) {
            if (available.empty()) {
                break;
            }
            ll put = lower_bound(available.begin(), available.end(), b.second) -
                     available.begin();
            if (put < available.size()) {
                ans += b.first;
                available.erase(available.begin() + put);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
