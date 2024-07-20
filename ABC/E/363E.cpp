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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll H, W, Y;
    cin >> H >> W >> Y;
    vvll A(H, vll(W));
    rep(i, H) rep(j, W) cin >> A.at(i).at(j);
    vector<vector<bool>> selected(H, vector<bool>(W, false));
    vector<vector<bool>> sank(H, vector<bool>(W, false));

    ll level = 0;
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>>
        pq;
    rep(i, H) {
        selected.at(i).at(0) = true;
        selected.at(i).at(W - 1) = true;
        pq.push({A.at(i).at(0), {i, 0}});
        pq.push({A.at(i).at(W - 1), {i, W - 1}});
    }
    rep(j, W) {
        if (j == 0 || j == W - 1) continue;
        selected.at(0).at(j) = true;
        selected.at(H - 1).at(j) = true;
        pq.push({A.at(0).at(j), {0, j}});
        pq.push({A.at(H - 1).at(j), {H - 1, j}});
    }
    ll rem = H * W;
    rep(i, Y) {
        level++;
        while (!pq.empty()) {
            auto [a, p] = pq.top();
            if (a > level) break;
            pq.pop();
            if (sank.at(p.first).at(p.second)) continue;
            sank.at(p.first).at(p.second) = true;
            rem--;
            if (rem == 0) break;
            ll x = p.first;
            ll y = p.second;
            if (x > 0) {
                if (!selected.at(x - 1).at(y)) {
                    selected.at(x - 1).at(y) = true;
                    pq.push({A.at(x - 1).at(y), {x - 1, y}});
                }
            }
            if (x < H - 1) {
                if (!selected.at(x + 1).at(y)) {
                    selected.at(x + 1).at(y) = true;
                    pq.push({A.at(x + 1).at(y), {x + 1, y}});
                }
            }
            if (y > 0) {
                if (!selected.at(x).at(y - 1)) {
                    selected.at(x).at(y - 1) = true;
                    pq.push({A.at(x).at(y - 1), {x, y - 1}});
                }
            }
            if (y < W - 1) {
                if (!selected.at(x).at(y + 1)) {
                    selected.at(x).at(y + 1) = true;
                    pq.push({A.at(x).at(y + 1), {x, y + 1}});
                }
            }
        }
        cout << rem << endl;
    }
    if (level < Y) {
        rep(i, Y - level) { cout << 0 << endl; }
    }

    return 0;
}
