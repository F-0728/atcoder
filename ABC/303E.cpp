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
    vector<set<ll>> G(N);
    rep(i, N - 1){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    vll ans;
    rep(i, N) {
        if (G.at(i).size() > 2) {
            ans.push_back(G.at(i).size());
            for (auto x : G.at(i)) {
                G.at(x).erase(i);
            }
            G.at(i).clear();
        }
    }
    dsu d(N);
    rep(i, N) {
        for (auto x : G.at(i)) {
            d.merge(i, x);
        }
    }
    vector<vector<int>> groups = d.groups();
    for (auto group : groups) {
        if (group.size() > 1) {
            rep(i, group.size() / 3) {
                ans.push_back(2);
            }
        }
    }
    sort(ans.begin(), ans.end());
    outv(ans);

    return 0;
}
