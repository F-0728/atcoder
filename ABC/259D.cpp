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
    ll N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vvll G(N);
    vvll circles(N, vll(3));
    ll S, T;
    rep(i, N) {
        ll x, y, r;
        cin >> x >> y >> r;
        circles.at(i) = {x, y, r};
        ll dx = circles.at(i).at(0) - sx;
        ll dy = circles.at(i).at(1) - sy;
        ll d = dx * dx + dy * dy;
        if (d == circles.at(i).at(2) * circles.at(i).at(2)) {
            S = i;
        }
        dx = circles.at(i).at(0) - tx;
        dy = circles.at(i).at(1) - ty;
        d = dx * dx + dy * dy;
        if (d == circles.at(i).at(2) * circles.at(i).at(2)) {
            T = i;
        }
        rep(j, i) {
            dx = circles.at(i).at(0) - circles.at(j).at(0);
            dy = circles.at(i).at(1) - circles.at(j).at(1);
            d = dx * dx + dy * dy;
            if (d <= (circles.at(i).at(2) + circles.at(j).at(2)) * (circles.at(i).at(2) + circles.at(j).at(2)) &&
                d >= (circles.at(i).at(2) - circles.at(j).at(2)) * (circles.at(i).at(2) - circles.at(j).at(2))) {
                G.at(i).push_back(j);
                G.at(j).push_back(i);
            }
        }
    }
    dsu d(N);
    rep(i, N) {
        for (ll j : G.at(i)) {
            d.merge(i, j);
        }
    }
    if (d.same(S, T)) {
        Yes;
    } else {
        No;
    }

    return 0;
}
