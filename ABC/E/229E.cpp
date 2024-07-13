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
    vvll edge(N);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) {
            swap(u, v);
        }
        edge.at(u).push_back(v);
    }
    dsu d(N);
    vll ans(N + 1);
    ans.at(N) = 0;
    for (ll i = N - 1; i >= 1; i--) {
        ans.at(i) = ans.at(i + 1) + 1;
        for (ll j : edge.at(i)) {
            if (!d.same(i, j)) {
                ans.at(i) -= 1;
            }
            d.merge(i, j);
        }
    }
    rep(i, N + 1) {
        if (i == 0) continue;
        cout << ans.at(i) << endl;
    }

    return 0;
}
