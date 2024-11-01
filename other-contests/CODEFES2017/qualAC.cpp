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
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vll count(26, 0);
    rep(i, H) {
        rep(j, W) { count.at(S[i][j] - 'a')++; }
    }

    ll once = 0;
    if (H % 2 == 1 && W % 2 == 1) {
        once++;
    }
    ll twice = 0;
    if (H % 2 == 1) {
        twice += W / 2;
    }
    if (W % 2 == 1) {
        twice += H / 2;
    }

    ll four = H * W;
    four -= once;
    four -= twice * 2;
    four /= 4;

    // cout << once << " " << twice << " " << four << endl;

    rep(j, once) {
        rep(i, 26) {
            if (count.at(i) % 4 == 1 || count.at(i) % 4 == 3) {
                count.at(i)--;
                break;
            }
        }
    }
    rep(j, twice) {
        bool found = false;
        rep(i, 26) {
            if (count.at(i) % 4 == 2) {
                count.at(i) -= 2;
                found = true;
                break;
            }
        }
        if (j < twice - 1 && !found) {
            rep(i, 26) {
                if (count.at(i) % 4 == 0 && count.at(i) != 0) {
                    count.at(i) -= 4;
                    j++;
                    break;
                }
            }
        }
    }
    rep(j, four) {
        rep(i, 26) {
            if (count.at(i) % 4 == 0 && count.at(i) != 0) {
                count.at(i) -= 4;
                break;
            }
        }
    }

    bool ok = true;
    rep(i, 26) {
        if (count.at(i) != 0) {
            ok = false;
            break;
        }
    }

    if (ok) {
        Yes;
    } else {
        No;
    }

    return 0;
}
