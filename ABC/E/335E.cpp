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
    vll A(N);
    rep(i, N) cin >> A[i];

    scc_graph G(N);
    vvll g(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (A[a] > A[b]) {
            G.add_edge(a, b);
            g[a].push_back(b);
        } else if (A[a] < A[b]) {
            G.add_edge(b, a);
            g[b].push_back(a);
        } else {
            G.add_edge(a, b);
            G.add_edge(b, a);
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    auto scc = G.scc();
    reverse(scc.begin(), scc.end());
    vll score(N, -INF);
    score[0] = 1;
    for (auto& vl : scc) {
        ll maxScore = -INF;
        for (ll v : vl) {
            for (ll prev : g[v]) {
                if (A[prev] == A[v]) {
                    score[v] = max(score[v], score[prev]);
                } else {
                    score[v] = max(score[v], score[prev] + 1);
                }
            }
            maxScore = max(maxScore, score[v]);
        }
        for (ll v : vl) {
            score[v] = maxScore;
        }
    }

    cout << max(0LL, score[N - 1]) << endl;

    return 0;
}
