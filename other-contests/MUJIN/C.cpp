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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vpll edges(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[i] = {a, b};
    }

    ll ans = 0;
    rep(i, 1 << N) {
        dsu d(N);
        rep(j, M) {
            ll u = edges[j].first;
            ll v = edges[j].second;
            if (((i >> u) & 1) != ((i >> v) & 1)) {
                d.merge(u, v);
            }
        }
        if (d.groups().size() == 1) {
            ans++;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}
