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

void dfs(pll current, vvll& dist, vector<string>& grid, vpll& dir) {
    for (auto d : dir) {
        ll x = current.first + d.first;
        ll y = current.second + d.second;
        if (x < 0 || x >= dist.size() || y < 0 || y >= dist.at(0).size()) {
            continue;
        }
        if (grid.at(x).at(y) == '#') {
            continue;
        }
        if (grid.at(x).at(y) == 'S') {
            if (dist.at(current.first).at(current.second) > 2) {
                dist.at(x).at(y) = dist.at(current.first).at(current.second) + 1;
                return;
            }
        }
        if (dist.at(x).at(y) != INF) {
            continue;
        }
        dist.at(x).at(y) = dist.at(current.first).at(current.second) + 1;
        dfs({x, y}, dist, grid, dir);
    }
}

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) {
        cin >> grid.at(i);
    }
    pll start;
    rep(i, H) {
        rep(j, W) {
            if (grid.at(i).at(j) == 'S') {
                start = {i, j};
            }
        }
    }
    vvll dist(H, vll(W, INF));
    dist.at(start.first).at(start.second) = 0;
    vpll dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    dfs(start, dist, grid, dir);
    if (dist.at(start.first).at(start.second) == 0) {
        No;
        return 0;
    }
    Yes;

    

    return 0;
}
