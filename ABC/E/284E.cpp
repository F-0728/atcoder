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

void dfs(ll v, ll p, vvll& G, vector<bool>& visited, ll& ans) {
    ans++;
    if (ans > 1e6) {
        cout << 1000000 << endl;
        exit(0);
    }
    for (auto nv : G.at(v)) {
        if (nv == p) continue;
        if (visited.at(nv)) continue;
        visited.at(nv) = true;
        dfs(nv, v, G, visited, ans);
        visited.at(nv) = false;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vvll G(N);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }
    vector<bool> visited(N, false);
    ll ans = 0;
    visited.at(0) = true;
    dfs(0, -1, G, visited, ans);
    cout << ans << endl;

    return 0;
}
