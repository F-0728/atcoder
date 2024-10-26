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
    ll N, K;
    cin >> N >> K;
    vll P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }

    scc_graph scc(N);
    rep(i, N) {
        scc.add_edge(P[i], i);
    }
    auto sccs = scc.scc();

    vvll doubling(60, vll(N));
    rep(i, N) {
        doubling.at(0).at(i) = P.at(i);
    }
    rep(i, 59) {
        rep(j, N) {
            doubling.at(i + 1).at(j) = doubling.at(i).at(doubling.at(i).at(j));
        }
    }

    vll ans(N);
    for (auto& scc : sccs) {
        ll rem = pow_mod(2, K, scc.size());
        for (auto& v : scc) {
            ll now = v;
            rep(i, 60) {
                if (rem & (1LL << i)) {
                    now = doubling.at(i).at(now);
                }
            }
            ans.at(v) = now;
        }
    }

    rep(i, N) {
        cout << ans.at(i) + 1 << " ";
    }
    cout << endl;

    return 0;
}
