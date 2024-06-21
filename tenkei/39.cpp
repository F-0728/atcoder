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

void dfs(ll v, ll p, vvll& G, vll& dp){
    dp.at(v) = 1;
    for(auto u : G.at(v)){
        if(u == p) continue;
        dfs(u, v, G, dp);
        dp.at(v) += dp.at(u);
    }
}

int main() {
    ll N;
    cin >> N;
    vvll G(N);
    rep(i, N - 1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    vll dp(N, 0);
    dfs(0, -1, G, dp);
    ll ans = 0;
    rep(i, N){
        ans += dp.at(i) * (N - dp.at(i));
    }
    cout << ans << endl;

    return 0;
}
