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
    vll grid(9);
    rep(i, 9) cin >> grid.at(i);
    set<vll> gakkari;
    vvll lines = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    for (vll line : lines) {
        if (grid.at(line.at(0)) == grid.at(line.at(1))) {
            gakkari.insert(line);
        }
        if (grid.at(line.at(1)) == grid.at(line.at(2))) {
            gakkari.insert({line.at(1), line.at(2), line.at(0)});
        }
        if (grid.at(line.at(2)) == grid.at(line.at(0))) {
            gakkari.insert({line.at(2), line.at(0), line.at(1)});
        }
    }
    ll okCount = 0;
    vll index = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vll revealOrder(9);
    rep(i, 9) {
        revealOrder.at(index.at(i)) = i;
    }
    bool ok = true;
    for (vll g : gakkari) {
        if (revealOrder.at(g.at(0)) < revealOrder.at(g.at(2))) {
            if (revealOrder.at(g.at(1)) < revealOrder.at(g.at(2))) {
                ok = false;
                break;
            }
        }
    }
    if (ok) okCount++;
    while (next_permutation(index.begin(), index.end())) {
        rep(i, 9) {
            revealOrder.at(index.at(i)) = i;
        }
        ok = true;
        for (vll g : gakkari) {
            if (revealOrder.at(g.at(0)) < revealOrder.at(g.at(2))) {
                if (revealOrder.at(g.at(1)) < revealOrder.at(g.at(2))) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) okCount++;
    }
    double ans = (double)okCount / 362880;
    cout << fixed << setprecision(10) << ans << endl;





    return 0;
}
