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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    mf_graph<ll> G(N + 26);
    rep(i, N) {
        G.add_edge(0, i + 1, 10);
        string S;
        cin >> S;
        rep(j, 24) {
            if (S.at(j) == '1') G.add_edge(i + 1, N + j + 1, 1);
        }
    }
    rep(i, 24) {
        G.add_edge(N + i + 1, N + 25, M);
    }

    ll ans = G.flow(0, N + 25);
    if (ans == M * 24) Yes;
    else No;

    return 0;
}
