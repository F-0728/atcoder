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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vector<vector<pair<ll, ll>>> G(100005);
vll ans(100005);

void dfs(ll v, ll prev, ll color) {
    set<ll> colorUsed;
    colorUsed.insert(color);
    ll c = 1;
    for (pair<ll, ll> edge : G.at(v)) {
        if (edge.first == prev) continue;
        while (colorUsed.count(c) > 0) c++;
        ans.at(edge.second) = c;
        dfs(edge.first, v, c);
        c++;
    }
}

int main() {
    ll N;
    cin >> N;
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    ll K = 0;
    rep(i, N) { K = max(K, (ll)G.at(i).size()); }
    cout << K << endl;

    dfs(0, -1, -1);
    rep(i, N - 1) { cout << ans.at(i) << endl; }

    return 0;
}
