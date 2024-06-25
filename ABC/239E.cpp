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

vvll top20;
void dfs(ll v, ll p, vvll& G, vll& value) {
    priority_queue<ll> pq;
    pq.push(value.at(v));
    for (ll u : G.at(v)) {
        if (u == p) continue;
        dfs(u, v, G, value);
        vll vu = top20.at(u);
        for (ll num : vu) {
            pq.push(num);
        }
    }
    vll res;
    rep(i, 20) {
        if (pq.empty()) break;
        res.push_back(pq.top());
        pq.pop();
    }
    top20.at(v) = res;
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vll value(N);
    rep(i, N) cin >> value.at(i);
    vvll G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    top20.resize(N);
    dfs(0, -1, G, value);
    rep(i, Q) {
        ll v, k;
        cin >> v >> k;
        v--;
        vll res = top20.at(v);
        cout << res.at(k - 1) << endl;
    }

    return 0;
}
