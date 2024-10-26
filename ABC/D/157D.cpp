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
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    dsu d(N);
    vvll friends(N), blocks(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        d.merge(a, b);
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    rep(i, K) {
        ll c, d;
        cin >> c >> d;
        c--, d--;
        blocks[c].push_back(d);
        blocks[d].push_back(c);
    }

    auto groups = d.groups();
    vll ans(N, 0);
    for (auto group : groups) {
        for (ll i : group) {
            ans[i] = group.size() - 1 - friends[i].size();
            for (ll j : blocks[i]) {
                if (d.same(i, j)) {
                    ans[i]--;
                }
            }
        }
    }

    outv(ans);

    return 0;
}
