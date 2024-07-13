#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

void dfs(ll v, ll p, vvll &G, vll &color, vll &cnt, vll &ans) {
    cnt.at(color.at(v))++;
    for (ll u : G.at(v)) {
        if (u == p) {
            continue;
        }
        dfs(u, v, G, color, cnt, ans);
    }
    if (cnt.at(color.at(v)) == 1) {
        ans.push_back(v);
    }
    cnt.at(color.at(v))--;
}

int main() {
    ll N;
    cin >> N;
    vll color(N);
    rep(i, N) cin >> color.at(i);
    vll ans;
    vvll G(N);
    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }
    vll cnt(100005, 0);
    dfs(0, -1, G, color, cnt, ans);
    sort(ans.begin(), ans.end());
    for (ll a : ans) {
        cout << a + 1 << endl;
    }
    return 0;
}
