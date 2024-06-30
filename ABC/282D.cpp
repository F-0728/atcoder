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

void dfs(ll v, ll p, vvll& G, vll& color) {
    for (auto nv : G.at(v)) {
        if (nv == p) continue;
        if (color.at(nv) != -1) {
            if (color.at(nv) == color.at(v)) {
                cout << 0 << endl;
                exit(0);
            }
            continue;
        }
        color.at(nv) = 1 - color.at(v);
        dfs(nv, v, G, color);
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    dsu d(N);
    vvll G(N);
    vpll edges(M);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        d.merge(A, B);
        G.at(A).push_back(B);
        G.at(B).push_back(A);
        edges.at(i) = {A, B};
    }
    vector<vector<int>> groups = d.groups();
    vll color(N, -1);
    ll ans = 0;
    ll allEdges = N * (N - 1) / 2;
    for (auto group : groups) {
        ll v = group.at(0);
        color.at(v) = 1;
        dfs(v, -1, G, color);
        ll color1 = 0, color2 = 0;
        ll m = 0;
        for (ll v : group) {
            if (color.at(v) == 1) color1++;
            else if (color.at(v) == 0) color2++;
            else {
                cout << 0 << endl;
                return 0;
            }
            m += G.at(v).size();
        }
        m /= 2;
        ans += color1 * color2 - m;
        allEdges -= group.size() * (group.size() - 1) / 2;
    }
    ans += allEdges;
    cout << ans << endl;

    return 0;
}
