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

vector<vector<mint>> dp(100005, vector<mint>(2, 1));
vvll G(100005);

void dfs(ll v, ll p) {
    for (ll child : G.at(v)) {
        if (child == p) continue;
        dfs(child, v);
        dp.at(v).at(0) *= dp.at(child).at(0) + dp.at(child).at(1);
        dp.at(v).at(1) *= dp.at(child).at(0);
    }
}

int main() {
    ll N;
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    mint ans = dp.at(0).at(0) + dp.at(0).at(1);
    cout << ans.val() << endl;

    return 0;
}
