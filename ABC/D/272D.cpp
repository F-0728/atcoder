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
    ll N, M;
    cin >> N >> M;
    vll squares;
    for (ll i = 0; i * i <= M; i++) {
        squares.push_back(i * i);
    }
    vvll grid(N, vll(N, -1));
    grid.at(0).at(0) = 0;
    queue<vll> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        vll p = q.front();
        q.pop();
        ll x = p.at(0);
        ll y = p.at(1);
        ll d = p.at(2);
        for (ll i = 0; i < squares.size(); i++) {
            ll s = squares.at(i);
            if (s > M / 2) break;
            ll t = lower_bound(squares.begin(), squares.end(), M - s) -
                   squares.begin();
            if (t == squares.size()) continue;
            if (squares.at(t) + s == M) {
                // cout << s << " " << squares.at(t) << endl;
                if (x + i < N && y + t < N) {
                    if (grid.at(x + i).at(y + t) == -1 ||
                        grid.at(x + i).at(y + t) > d + 1) {
                        grid.at(x + i).at(y + t) = d + 1;
                        q.push({x + i, y + t, d + 1});
                    }
                }
                if (x + t < N && y + i < N) {
                    if (grid.at(x + t).at(y + i) == -1 ||
                        grid.at(x + t).at(y + i) > d + 1) {
                        grid.at(x + t).at(y + i) = d + 1;
                        q.push({x + t, y + i, d + 1});
                    }
                }
                if (x - i >= 0 && y - t >= 0) {
                    if (grid.at(x - i).at(y - t) == -1 ||
                        grid.at(x - i).at(y - t) > d + 1) {
                        grid.at(x - i).at(y - t) = d + 1;
                        q.push({x - i, y - t, d + 1});
                    }
                }
                if (x - t >= 0 && y - i >= 0) {
                    if (grid.at(x - t).at(y - i) == -1 ||
                        grid.at(x - t).at(y - i) > d + 1) {
                        grid.at(x - t).at(y - i) = d + 1;
                        q.push({x - t, y - i, d + 1});
                    }
                }
                if (x + i < N && y - t >= 0) {
                    if (grid.at(x + i).at(y - t) == -1 ||
                        grid.at(x + i).at(y - t) > d + 1) {
                        grid.at(x + i).at(y - t) = d + 1;
                        q.push({x + i, y - t, d + 1});
                    }
                }
                if (x + t < N && y - i >= 0) {
                    if (grid.at(x + t).at(y - i) == -1 ||
                        grid.at(x + t).at(y - i) > d + 1) {
                        grid.at(x + t).at(y - i) = d + 1;
                        q.push({x + t, y - i, d + 1});
                    }
                }
                if (x - i >= 0 && y + t < N) {
                    if (grid.at(x - i).at(y + t) == -1 ||
                        grid.at(x - i).at(y + t) > d + 1) {
                        grid.at(x - i).at(y + t) = d + 1;
                        q.push({x - i, y + t, d + 1});
                    }
                }
                if (x - t >= 0 && y + i < N) {
                    if (grid.at(x - t).at(y + i) == -1 ||
                        grid.at(x - t).at(y + i) > d + 1) {
                        grid.at(x - t).at(y + i) = d + 1;
                        q.push({x - t, y + i, d + 1});
                    }
                }
            }
        }
    }
    rep(i, N) { outv(grid.at(i)); }

    return 0;
}
