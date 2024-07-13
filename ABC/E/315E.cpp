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
    ll N;
    cin >> N;
    vvll G(N);
    rep(i, N) {
        ll K;
        cin >> K;
        rep(j, K) {
            ll P;
            cin >> P;
            P--;
            G.at(i).push_back(P);
        }
    }
    scc_graph g(N);
    dsu d(N);
    queue<pll> q;
    q.push({0, -1});
    while (!q.empty()) {
        pll p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        if (y != -1) {
            if (d.same(x, y)) continue;
            d.merge(x, y);
        }
        for (ll a : G.at(x)) {
            q.push({a, x});
        }
    }
    rep(i, N) {
        if (!d.same(0, i)) continue;
        for (ll a : G.at(i)) {
            if (d.same(0, a)) {
                g.add_edge(i, a);
            }
        }
    }
    auto scc = g.scc();
    vll ans;
    rep(i, scc.size()) {
        ll a = scc.at(i).at(0);
            if (a != 0 && d.same(0, a)) {
                ans.push_back(a);
            }
    }
    rep(i, ans.size()) {
        // outv(scc.at(ans.size() - 1 - i));
        cout << ans.at(ans.size() - 1 - i) + 1 << " ";
    }
    cout << endl;

    return 0;
}
