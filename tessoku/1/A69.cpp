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

struct Edge { 
    ll rev, from, to, cap;
};

class FordFulkerson {
public:
    vector<vector<Edge>> G;
    vector<bool> visited;

    ll size = 0;
    void init(ll n) {
        G.resize(n);
        visited.resize(n);
        size = n;
    }

    void add_edge(ll u, ll v, ll cost) {
        ll u_vID = G.at(u).size();
        ll v_uID = G.at(v).size();
        G.at(u).emplace_back(Edge{v_uID, u, v, cost});
        G.at(v).emplace_back(Edge{u_vID, v, u, 0});
    }

    ll dfs(ll pos, ll goal, ll F) {
        if (pos == goal) return F;
        visited.at(pos) = true;
        for(Edge &e : G.at(pos)){
            if (e.cap == 0 or visited.at(e.to)) continue;
            ll flow = dfs(e.to, goal, min(F, e.cap));
            if (flow > 0) {
                e.cap -= flow;
                G.at(e.to).at(e.rev).cap += flow;
                return flow;
            }
        }
        return 0;
    }

    ll maxFlow(ll s, ll t) {
        ll totalFlow = 0;
        while (1) {
            visited.assign(size, false);
            ll F = dfs(s, t, INF);
            if (F == 0) break;
            totalFlow += F;
        }
        return totalFlow;
    }
};


int main() {
    ll N;
    cin >> N;
    vector<string> C(N);
    rep(i, N) cin >> C.at(i);

    FordFulkerson ff;
    ff.init(2 * N + 2);
    rep(i, N) {
        ff.add_edge(0, i + 1, 1);
        ff.add_edge(N + i + 1, 2 * N + 1, 1);
    }
    rep(i, N) {
        rep(j, N) {
            if (C.at(i).at(j) == '#') {
                ff.add_edge(i + 1, j + N + 1, 1);
            }
        }
    }
    cout << ff.maxFlow(0, 2 * N + 1) << endl;
    return 0;
}
