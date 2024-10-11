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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll H1, W1;
    cin >> H1 >> W1;
    vvll A(H1, vll(W1));
    rep(i, H1) rep(j, W1) cin >> A[i][j];

    ll H2, W2;
    cin >> H2 >> W2;
    vvll B(H2, vll(W2));
    rep(i, H2) rep(j, W2) cin >> B[i][j];

    ll deleteH = H1 - H2;
    ll deleteW = W1 - W2;

    rep(i, 1 << H1) {
        if (popcount(unsigned(i)) != deleteH) {
            continue;
        }
        rep(j, 1 << W1) {
            if (popcount(unsigned(j)) != deleteW) {
                continue;
            }
            vvll newA(H2, vll(W2));
            vll mapH, mapW;
            rep(k, H1) {
                if (i & (1 << k)) {
                    continue;
                }
                mapH.push_back(k);
            }
            rep(k, W1) {
                if (j & (1 << k)) {
                    continue;
                }
                mapW.push_back(k);
            }
            rep(k, H2) {
                rep(l, W2) {
                    newA[k][l] = A[mapH[k]][mapW[l]];
                }
            }
            bool ok = true;
            rep(k, H2) {
                rep(l, W2) {
                    if (newA[k][l] != B[k][l]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                Yes;
                return 0;
            }
        }
    }

    No;

    return 0;
}
