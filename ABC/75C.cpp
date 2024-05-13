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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

bool isConnected(dsu g, ll n) {
    if (g.size(0) == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> edges(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[i] = {a, b};
    }

    ll ans = 0;

    rep(i, M) {
        dsu G(N);
        rep(j, M) {
            if (i == j) {
                continue;
            }
            G.merge(edges[j].first, edges[j].second);
        }
        if (!isConnected(G, N)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
