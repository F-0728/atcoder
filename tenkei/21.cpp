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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    scc_graph g(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }
    auto scc = g.scc();
    ll ans = 0;
    for (auto& v : scc) {
        ans += v.size() * (v.size() - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
