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
    ll N, M;
    cin >> N >> M;
    vvll subG(M);
    vpll cost(M);
    rep(i, M) {
        ll K, C;
        cin >> K >> C;
        cost[i] = {C, i};
        rep(j, K) {
            ll A;
            cin >> A;
            A--;
            subG[i].push_back(A);
        }
    }
    sort(cost.begin(), cost.end());

    dsu d(N);
    ll ans = 0;
    for(auto [C, i] : cost) {
        ll top = subG[i][0];
        for (ll v : subG[i]) {
            if (!d.same(top, v)) {
                d.merge(top, v);
                ans += C;
            }
        }
    }

    if (d.size(0) == N) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
