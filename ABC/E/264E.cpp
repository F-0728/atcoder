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

int main() {
    ll N, M, E;
    cin >> N >> M >> E;

    vpll edges(E);
    rep(i, E) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        edges[i] = {min(a, N), min(b, N)};
    }

    ll Q;
    cin >> Q;
    vll query(Q);
    vector<bool> stop(E, false);
    rep(i, Q) {
        cin >> query[i];
        query[i]--;
        stop[query[i]] = true;
    }

    reverse(query.begin(), query.end());

    dsu d(N + 1);

    rep(i, E) {
        if (stop[i]) continue;
        ll u = edges[i].first;
        ll v = edges[i].second;
        d.merge(u, v);
    }

    vll ans(Q);
    rep(i, Q) {
        ans[i] = d.size(N) - 1;
        ll u = edges[query[i]].first;
        ll v = edges[query[i]].second;
        d.merge(u, v);
    }

    reverse(ans.begin(), ans.end());

    rep(i, Q) {
        cout << ans[i] << endl;
    }


    return 0;
}
