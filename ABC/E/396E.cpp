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

int main() {
    ll N, M;
    cin >> N >> M;
    vll X(M), Y(M), Z(M);
    rep(i, M) {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;
    }
    
    vll A(N, 0);
    rep(i, 30) {
        vector<vpll> G(N);
        dsu d(N);
        rep(j, M) {
            if ((Z[j] >> i) & 1) {
                G[X[j]].push_back({Y[j], 1});
                G[Y[j]].push_back({X[j], 1});
            } else {
                G[X[j]].push_back({Y[j], 0});
                G[Y[j]].push_back({X[j], 0});
            }
            d.merge(X[j], Y[j]);
        }
        vll color(N, -1);
        auto groups = d.groups();
        for (auto group : groups) {
            ll count0 = 0, count1 = 0;
            queue<ll> q;
            q.push(group[0]);
            color[group[0]] = 0;
            count0++;
            while (!q.empty()) {
                ll u = q.front();
                q.pop();
                for (auto [v, w] : G[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ w;
                        if (color[v] == 0) {
                            count0++;
                        } else {
                            count1++;
                        }
                        q.push(v);
                    } else {
                        if (color[v] != (color[u] ^ w)) {
                            cout << -1 << "\n";
                            return 0;
                        }
                    }
                }
            }
            if (count1 > count0) {
                for (ll u : group) {
                    color[u] ^= 1;
                }
            }
            for (ll u : group) {
                A[u] |= (color[u] << i);
            }
        }
    }

    outv(A);

    return 0;
}
