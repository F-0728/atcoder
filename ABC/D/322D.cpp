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

vector<vector<char>> rotate(vector<vector<char>> S) {
    vector<vector<char>> res(4, vector<char>(4));
    rep(i, 4) {
        rep(j, 4) {
            res[j][3 - i] = S[i][j];
        }
    }
    return res;
}

int main() {
    vector<vector<vector<char>>> S(3, vector<vector<char>>(4, vector<char>(4)));
    rep(i, 3) {
        rep(j, 4) {
            string s;
            cin >> s;
            rep(k, 4) {
                S[i][j][k] = s[k];
            }
        }
    }

    rep(i, 16) {
        vll rot(3, 0);
        rot[1] = i % 4;
        rot[2] = i / 4 % 4;

        vector<vector<vector<char>>> T(3, vector<vector<char>>(4, vector<char>(4)));
        rep(j, 3) {
            vector<vector<char>> tmp = S[j];
            rep(k, rot[j]) {
                tmp = rotate(tmp);
            }
            T[j] = tmp;
        }
        for (ll i1 = -3; i1 <= 3; i1++) {
            for (ll j1 = -3; j1 <= 3; j1++) {
                for (ll i2 = -3; i2 <= 3; i2++) {
                    for (ll j2 = -3; j2 <= 3; j2++) {
                        for (ll i3 = -3; i3 <= 3; i3++) {
                            for (ll j3 = -3; j3 <= 3; j3++) {
                                bool ok = true;
                                vector<vector<char>> now(4, vector<char>(4, '.'));
                                rep(k, 4) {
                                    rep(l, 4) {
                                        if (0 <= i1 + k && i1 + k < 4 && 0 <= j1 + l && j1 + l < 4) {
                                            if (T[0][k][l] == '#') {
                                                if (now[i1 + k][j1 + l] == '#') {
                                                    ok = false;
                                                    break;
                                                }
                                                now[i1 + k][j1 + l] = '#';
                                            }
                                        } else {
                                            if (T[0][k][l] == '#') {
                                                ok = false;
                                                break;
                                            }
                                        }
                                        if (0 <= i2 + k && i2 + k < 4 && 0 <= j2 + l && j2 + l < 4) {
                                            if (T[1][k][l] == '#') {
                                                if (now[i2 + k][j2 + l] == '#') {
                                                    ok = false;
                                                    break;
                                                }
                                                now[i2 + k][j2 + l] = '#';
                                            }
                                        } else {
                                            if (T[1][k][l] == '#') {
                                                ok = false;
                                                break;
                                            }
                                        }
                                        if (0 <= i3 + k && i3 + k < 4 && 0 <= j3 + l && j3 + l < 4) {
                                            if (T[2][k][l] == '#') {
                                                if (now[i3 + k][j3 + l] == '#') {
                                                    ok = false;
                                                    break;
                                                }
                                                now[i3 + k][j3 + l] = '#';
                                            }
                                        } else {
                                            if (T[2][k][l] == '#') {
                                                ok = false;
                                                break;
                                            }
                                        }
                                    }
                                }
                                rep(k, 4) {
                                    rep(l, 4) {
                                        if (now[k][l] == '.') {
                                            ok = false;
                                        }
                                    }
                                }
                                if (ok) {
                                    cout << "Yes" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    

    return 0;
}
