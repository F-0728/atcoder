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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    vvll A(6, vll(6, 0));
    rep(i, 4) {
        rep(j, 4) { cin >> A[i + 1][j + 1]; }
    }
    ll ans = 0;
    rep(i, 1 << 16) {
        vector<vector<bool>> is_inside(6, vector<bool>(6, false));
        rep(k, 4) {
            rep(l, 4) {
                if (i & (1 << (k * 4 + l))) {
                    is_inside[k + 1][l + 1] = true;
                }
            }
        }
        dsu d(36);
        rep(k, 6) {
            rep(l, 6) {
                if (is_inside[k][l]) {
                    for (auto [dx, dy] : dir) {
                        if (k + dx >= 0 && k + dx < 6 && l + dy >= 0 &&
                            l + dy < 6) {
                            if (is_inside[k + dx][l + dy]) {
                                d.merge(k * 6 + l, (k + dx) * 6 + l + dy);
                            }
                        }
                    }
                } else {
                    for (auto [dx, dy] : dir) {
                        if (k + dx >= 0 && k + dx < 6 && l + dy >= 0 &&
                            l + dy < 6) {
                            if (!is_inside[k + dx][l + dy]) {
                                d.merge(k * 6 + l, (k + dx) * 6 + l + dy);
                            }
                        }
                    }
                }
            }
        }
        bool ok = true;
        rep(k, 6) {
            rep(j, 6) {
                if (A[k][j] == 1 && !is_inside[k][j]) {
                    ok = false;
                    break;
                }
            }
        }
        auto groups = d.groups();
        if (groups.size() > 2) {
            ok = false;
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
