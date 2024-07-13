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

int main() {
    ll N, M;
    cin >> N >> M;
    vvll G(N);
    dsu d(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
        d.merge(a, b);
    }

    ll K;
    cin >> K;
    map<pll, ll> mp;
    rep(i, K) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        mp[{d.leader(x), d.leader(y)}]++;
        mp[{d.leader(y), d.leader(x)}]++;
    }

    ll Q;
    cin >> Q;
    vpll query(Q);
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        query.at(i) = {d.leader(x), d.leader(y)};
        if (mp.find(query.at(i)) == mp.end()) {
            Yes;
        } else {
            No;
        }
    }

    return 0;
}
