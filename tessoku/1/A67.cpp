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
    vvll edges(M);
    dsu d(N);
    rep(i, M) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        edges.at(i) = {C, A, B};
    }
    sort(edges.begin(), edges.end());
    // kruskal's algorithm
    ll ans = 0;
    for (auto e : edges) {
        ll C = e.at(0);
        ll A = e.at(1);
        ll B = e.at(2);
        if (d.same(A, B)) continue;
        d.merge(A, B);
        ans += C;
    }
    cout << ans << endl;

    return 0;
}
