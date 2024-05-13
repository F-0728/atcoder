#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vector<ll> dp(100005, 0);
vector<vector<ll>> E(100005, vector<ll>(0));

void dfs1(ll v, ll p) {
    dp[v] = 0;
    for (ll u : E[v]) {
        if (u == p) {
            continue;
        }
        dfs1(u, v);
        dp[v] = max(dp[v], dp[u] + 1);
    }
    return;
}

ll dfs2(ll v, ll d_par, ll par) {
    vector<pair<ll, ll>> d_child;
    d_child.emplace_back(0, -1);
    for (ll u : E[v]) {
        if (u == par)
            d_child.emplace_back(d_par + 1, u);
        else
            d_child.emplace_back(1 + dp[u], u);
    }
    sort(d_child.rbegin(), d_child.rend());
    ll ret = d_child[0].first + d_child[1].first;
    for (ll u : E[v]) {
        if (u == par) {
            continue;
        }
        ret = max(ret, dfs2(u, d_child[d_child[0].second == u].first, v));
    }
    return ret;
}

int main() {
    ll N;
    ll A, B;
    cin >> N;
    vector<ll> d(N);
    rep(i, N - 1) {
        cin >> A >> B;
        E[A - 1].push_back(B - 1);
        E[B - 1].push_back(A - 1);
    }
    dfs1(0, -1);
    cout << dfs2(0, -1, 0) + 1 << endl;

    return 0;
}
