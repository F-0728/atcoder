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
    ll H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid.at(i);
    dsu d(H * W);
    vpll allRed;
    rep(i, H) rep(j, W) {
        if (grid.at(i).at(j) == '#') {
            if (i < H - 1 && grid.at(i + 1).at(j) == '#') {
                d.merge(i * W + j, (i + 1) * W + j);
            }
            if (j < W - 1 && grid.at(i).at(j + 1) == '#') {
                d.merge(i * W + j, i * W + j + 1);
            }
        } else {
            allRed.push_back({i, j});
        }
    }
    ll count = 0;
    ll all = allRed.size();
    for (pll red : allRed) {
        set<ll> s;
        ll i = red.first;
        ll j = red.second;
        if (i > 0 && grid.at(i - 1).at(j) == '#') {
            s.insert(d.leader((i - 1) * W + j));
        }
        if (i < H - 1 && grid.at(i + 1).at(j) == '#') {
            s.insert(d.leader((i + 1) * W + j));
        }
        if (j > 0 && grid.at(i).at(j - 1) == '#') {
            s.insert(d.leader(i * W + j - 1));
        }
        if (j < W - 1 && grid.at(i).at(j + 1) == '#') {
            s.insert(d.leader(i * W + j + 1));
        }
        if (s.size() == 0) {
            count++;
        } else {
            count -= s.size() - 1;
        }
    }
    ll dSize = 0;
    for (vector<int> group : d.groups()) {
        ll i = group.at(0) / W;
        ll j = group.at(0) % W;
        if (grid.at(i).at(j) == '#') {
            dSize++;
        }
    }
    mint ans = count;
    ans /= all;
    ans += dSize;
    cout << ans.val() << endl;

    return 0;
}
