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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

vvll G;
vll dist;
ll dfs(ll v, ll N) {
    if (dist.at(v) != -1) return dist.at(v);
    dist.at(v) = 0;
    // cout << v << endl;
    for (auto u : G.at(v)) {
        dist.at(v) = max(dist.at(v), dfs(u, N) + 1);
    }
    return dist.at(v);
}

int main() {
    ll N, M;
    cin >> N >> M;
    G.resize(N);
    vll indeg(N, 0);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G.at(u).push_back(v);
        indeg.at(v)++;
    }
    ll root = -1;
    rep(i, N) {
        if (indeg.at(i) == 0) {
            if (root != -1) {
                No;
                return 0;
            }
            root = i;
        }
    }
    if (root == -1) {
        No;
        return 0;
    }
    dist.resize(N, -1);
    dfs(root, N);
    ll maxDist = 0;
    rep(i, N) {
        maxDist = max(maxDist, dist.at(i));
    }
    // outv(dist);
    if (maxDist == N - 1) {
        Yes;
        vpll ans;
        rep(i, N) {
            ans.push_back({i + 1, N - dist.at(i) + 1 - 1});
        }
        sort(ans.begin(), ans.end());
        for (auto p : ans) {
            cout << p.second << " ";
        }
        cout << endl;
        return 0;

    }
    No;
    return 0;
}
