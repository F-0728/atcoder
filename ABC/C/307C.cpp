#include <atcoder/all>
#include <bitset>
#include <chrono>
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
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}
ll opsum(ll a, ll b) { return a + b; }
ll opmax(ll a, ll b) { return max(a, b); }
ll opmin(ll a, ll b) { return min(a, b); }
ll esum() { return 0; }
ll emax() { return -INF; }
ll emin() { return INF; }
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll HA, WA, HB, WB, HX, WX;
    cin >> HA >> WA;
    vector<string> A(HA);
    rep(i, HA) cin >> A[i];

    cin >> HB >> WB;
    vector<string> B(HB);
    rep(i, HB) cin >> B[i];

    cin >> HX >> WX;
    vector<string> X(HX);
    rep(i, HX) cin >> X[i];

    for (ll i = -WA + 1; i < WX; i++) {
        for (ll j = -HA + 1; j < HX; j++) {
            for (ll k = -WB + 1; k < WX; k++) {
                for (ll l = -HB + 1; l < HX; l++) {
                    vector<vector<char>> now(HX, vector<char>(WX, '.'));
                    vvbool selectedA(HA, vbool(WA, false));
                    vvbool selectedB(HB, vbool(WB, false));
                    for (ll m = 0; m < HA; m++) {
                        for (ll n = 0; n < WA; n++) {
                            if (0 <= j + m && j + m < HX && 0 <= i + n &&
                                i + n < WX) {
                                if (A[m][n] == '#') {
                                    now[j + m][i + n] = A[m][n];
                                }
                                selectedA[m][n] = true;
                            }
                        }
                    }
                    for (ll m = 0; m < HB; m++) {
                        for (ll n = 0; n < WB; n++) {
                            if (0 <= l + m && l + m < HX && 0 <= k + n &&
                                k + n < WX) {
                                if (B[m][n] == '#') {
                                    now[l + m][k + n] = B[m][n];
                                }
                                selectedB[m][n] = true;
                            }
                        }
                    }
                    bool ok = true;
                    for (ll m = 0; m < HX; m++) {
                        for (ll n = 0; n < WX; n++) {
                            if (X[m][n] != now[m][n]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    for (ll m = 0; m < HA; m++) {
                        for (ll n = 0; n < WA; n++) {
                            if (A[m][n] == '#' && !selectedA[m][n]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    for (ll m = 0; m < HB; m++) {
                        for (ll n = 0; n < WB; n++) {
                            if (B[m][n] == '#' && !selectedB[m][n]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    // cout << i << " " << j << " " << k << " " << l << endl;
                    // rep(m, HX) { 
                    //     rep(n, WX) {
                    //         cout << now[m][n];
                    //     }
                    //     cout << endl;
                    // }
                    if (ok) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
