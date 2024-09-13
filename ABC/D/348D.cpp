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

    pll start, goal;
    rep(i, H) {
        rep(j, W) {
            if (grid.at(i).at(j) == 'S') {
                start = {i, j};
            } else if (grid.at(i).at(j) == 'T') {
                goal = {i, j};
            }
        }
    }

    ll N;
    cin >> N;
    map<pll, ll> mp;
    rep(i, N) {
        ll r, c, h;
        cin >> r >> c >> h;
        mp[{r - 1, c - 1}] = h;
    }

    vvll hp(H, vll(W, -1));
    priority_queue<vll> q;
    q.push({0, start.first, start.second});
    while (!q.empty()) {
        vll now = q.top();
        q.pop();
        ll h = now.at(0);
        ll r = now.at(1);
        ll c = now.at(2);
        if (r < 0 || r >= H || c < 0 || c >= W) continue;
        if (grid.at(r).at(c) == '#') continue;
        if (hp.at(r).at(c) >= h) continue;
        if (h < 0) continue;
        if (r == goal.first && c == goal.second) {
            Yes;
            return 0;
        }
        if (mp[{r, c}] > h) {
            h = mp[{r, c}];
        } 
        hp.at(r).at(c) = h;
        q.push({h - 1, r + 1, c});
        q.push({h - 1, r - 1, c});
        q.push({h - 1, r, c + 1});
        q.push({h - 1, r, c - 1});
    }
    No;

    return 0;
}
