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
    rep(i, H) {
        cin >> grid.at(i);
    }
    vpll right, left, up, down;
    pll start, goal;
    vector<vector<bool>> ableToPass(H, vector<bool>(W, true));
    rep(i, H) {
        rep(j, W) {
            if (grid.at(i).at(j) == '>') {
                right.push_back({i, j});
            } else if (grid.at(i).at(j) == '<') {
                left.push_back({i, j});
            } else if (grid.at(i).at(j) == '^') {
                up.push_back({i, j});
            } else if (grid.at(i).at(j) == 'v') {
                down.push_back({i, j});
            } else if (grid.at(i).at(j) == 'G') {
                goal = {i, j};
            } else if (grid.at(i).at(j) == 'S') {
                start = {i, j};
            } else if (grid.at(i).at(j) == '#') {
                ableToPass.at(i).at(j) = false;
            }
        }
    }
    for (pll r : right) {
        ll i = r.first;
        ll j = r.second;
        ableToPass.at(i).at(j) = false;
        j++;
        while (j < W && grid.at(i).at(j) == '.') {
            ableToPass.at(i).at(j) = false;
            j++;
        }
    }
    for (auto l : left) {
        ll i = l.first;
        ll j = l.second;
        ableToPass.at(i).at(j) = false;
        j--;
        while (j >= 0 && grid.at(i).at(j) == '.') {
            ableToPass.at(i).at(j) = false;
            j--;
        }
    }
    for (auto u : up) {
        ll i = u.first;
        ll j = u.second;
        ableToPass.at(i).at(j) = false;
        i--;
        while (i >= 0 && grid.at(i).at(j) == '.') {
            ableToPass.at(i).at(j) = false;
            i--;
        }
    }
    for (auto d : down) {
        ll i = d.first;
        ll j = d.second;
        ableToPass.at(i).at(j) = false;
        i++;
        while (i < H && grid.at(i).at(j) == '.') {
            ableToPass.at(i).at(j) = false;
            i++;
        }
    }
    vvll dist(H, vll(W, INF));
    queue<pll> q;
    q.push(start);
    dist.at(start.first).at(start.second) = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i > 0 && ableToPass.at(i).at(j) && dist.at(i - 1).at(j) == INF) {
            dist.at(i - 1).at(j) = dist.at(i).at(j) + 1;
            q.push({i - 1, j});
        }
        if (i < H - 1 && ableToPass.at(i).at(j) && dist.at(i + 1).at(j) == INF) {
            dist.at(i + 1).at(j) = dist.at(i).at(j) + 1;
            q.push({i + 1, j});
        }
        if (j > 0 && ableToPass.at(i).at(j) && dist.at(i).at(j - 1) == INF) {
            dist.at(i).at(j - 1) = dist.at(i).at(j) + 1;
            q.push({i, j - 1});
        }
        if (j < W - 1 && ableToPass.at(i).at(j) && dist.at(i).at(j + 1) == INF) {
            dist.at(i).at(j + 1) = dist.at(i).at(j) + 1;
            q.push({i, j + 1});
        }
    }
    // rep(i, H) {
    //     outv(dist.at(i));
    // }
    // cout << goal.first << " " << goal.second << endl;
    if (dist.at(goal.first).at(goal.second) == INF) {
        cout << -1 << endl;
    } else {
        cout << dist.at(goal.first).at(goal.second) << endl;
    }

    return 0;
}
