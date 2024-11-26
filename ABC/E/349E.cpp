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

map<vvll, bool> mp;
vvll lines = {{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 1, 2},
              {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}};

bool canWin(vvll S, vvll& A) {
    if (mp.count(S)) {
        return mp[S];
    }
    ll count1 = 0;
    ll count2 = 0;
    rep(i, 3) {
        rep(j, 3) {
            if (S[i][j] == 1) {
                count1++;
            } else if (S[i][j] == 2) {
                count2++;
            }
        }
    }

    for (vll line : lines) {
        if (S[line[0] / 3][line[0] % 3] == S[line[1] / 3][line[1] % 3] &&
            S[line[1] / 3][line[1] % 3] == S[line[2] / 3][line[2] % 3]) {
            if (S[line[0] / 3][line[0] % 3] == 1) {
                return mp[S] = true;
            } else if (S[line[0] / 3][line[0] % 3] == 2) {
                return mp[S] = false;
            }
        }
    }
    if (count1 + count2 == 9) {
        ll score1 = 0, score2 = 0;
        rep(i, 3) {
            rep(j, 3) {
                if (S[i][j] == 1) {
                    score1 += A[i][j];
                } else if (S[i][j] == 2) {
                    score2 += A[i][j];
                }
            }
        }
        return mp[S] = score1 > score2;
    }

    bool res = false;
    if (count1 == count2) {
        res = false;
        rep(i, 3) {
            rep(j, 3) {
                if (S[i][j] == 0) {
                    vvll T = S;
                    T[i][j] = 1;
                    if (canWin(T, A)) {
                        res = true;
                    }
                }
            }
        }
    } else {
        res = true;
        rep(i, 3) {
            rep(j, 3) {
                if (S[i][j] == 0) {
                    vvll T = S;
                    T[i][j] = 2;
                    if (!canWin(T, A)) {
                        res = false;
                    }
                }
            }
        }
    }
    return mp[S] = res;
}

int main() {
    vvll A(3, vll(3));
    rep(i, 3) {
        rep(j, 3) { cin >> A[i][j]; }
    }

    vvll S(3, vll(3));
    rep(i, 3) {
        rep(j, 3) { S[i][j] = 0; }
    }

    bool ans = canWin(S, A);

    if (ans) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}
