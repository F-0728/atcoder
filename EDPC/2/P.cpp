#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

vvll G;
vector<mint> dpWhite;
vector<mint> dpBlack;
void dfs(ll v, ll p) {
    if (G[v].size() == 1 && G[v][0] == p) {
        return;
    }
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        dpWhite[v] *= dpWhite[u] + dpBlack[u];
        dpBlack[v] *= dpWhite[u];
    }
}

int main() {
    ll N;
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dpWhite.resize(N, 1);
    dpBlack.resize(N, 1);

    dfs(0, -1);

    cout << (dpWhite[0] + dpBlack[0]).val() << endl;

    return 0;
}
