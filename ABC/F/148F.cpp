#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
#include <bitset>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) { iota(idx.begin(), idx.end(), 0); sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; }); }
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << "\n";}
void outvmint(const vector<mint>& v){for(const auto& e : v){ cout << e.val() << " "; } cout << "\n";}
template<typename T> void outvv(const vector<vector<T>>& vv){for(const auto& v : vv){ outv(v); }}
void outvvmint(const vector<vector<mint>>& vv){for(const auto& v : vv){ outvmint(v); }}
template<typename T> void outvp(const vector<pair<T, T>>& vp){for(const auto& p : vp){ cout << p.first << " " << p.second << "\n"; }}

// グラフの型: vector<vector<Edge>> g(n)
// URL: https://qiita.com/Dunsparce/items/d3a832b71ac10becd33d

struct Edge {long long to;};
struct S_rmq {long long value; long long index;};
S_rmq op_rmq(S_rmq a, S_rmq b){
    if(a.value < b.value) return a;
    else return b;
}
S_rmq E_rmq(){return {(1LL << 60),-1LL};}

struct euler_tour {
    vector<long long> depth, visit;
    vector<long long> discover, finishing;
    vector<vector<Edge>> g;
    long long n;

    atcoder::segtree<S_rmq, op_rmq, E_rmq> rmq;

    euler_tour(long long n=1, vector<vector<Edge>> g=vector<vector<Edge>>()){
        init(n, g);
    }

    void init(long long n, vector<vector<Edge>> g){
        this->n = n;
        depth.clear();
        visit.clear();
        discover.assign(n, (1<<30));
        finishing.assign(n ,-1);
        this->g = g;
        this->g.resize(n);
    }

    void add_edge(long long u, long long v){
        g[u].push_back({v});
        g[v].push_back({u});
    }
    
    void dfs(long long root){
        Dfs(root, -1, 0);
        for(long long i=0;i<int(visit.size());i++){
            discover[visit[i]] = min(discover[visit[i]], i);
            finishing[visit[i]] = max(finishing[visit[i]], i+1);
        }
        vector<S_rmq> depth_v(int(depth.size()));
        for(long long i=0; i<int(depth.size()); i++){
            depth_v[i] = {depth[i], visit[i]};
        }

        rmq = atcoder::segtree<S_rmq, op_rmq, E_rmq>(depth_v);
    }

    void Dfs(long long v, long long p, long long d) {
        visit.push_back(v);
        depth.push_back(d);
        for (Edge u : g[v]) {
            if (u.to == p) continue;
            Dfs(u.to, v, d + 1);
            visit.push_back(v);
            depth.push_back(d);
        }
    }

    long long lca(long long u, long long v){
        return rmq.prod(min(discover[u], discover[v]), max(finishing[u], finishing[v])).index;
    }

    long long dist(long long u, long long v){
        return depth[discover[u]]+depth[discover[v]]-2*depth[discover[lca(u,v)]];
    }
};


int main() {
    ll N, u, v;
    cin >> N >> u >> v;
    u--;
    v--;
    vvll G(N);
    vector<vector<Edge>> g(N);
    rep(i, N - 1) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
        g[A].push_back({B});
        g[B].push_back({A});
    }

    euler_tour et(N, g);
    et.dfs(v);

    ll ans = 0;
    rep(i, N) {
        ll lca = et.lca(u, i);
        if (et.dist(u, lca) >= et.dist(v, lca)) continue;
        ans = max(ans, et.dist(v, i));
    }

    cout << ans - 1 << "\n";

    return 0;
}
