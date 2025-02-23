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
#define Yes cout << "Yes" << "\n"
#define No cout << "No" << "\n"
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
ll pc(ll x) { return __builtin_popcountll(x); }
void argsort(vll& v, vll& idx) {
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&v](ll i1, ll i2) { return v[i1] < v[i2]; });
}
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << "\n";
}
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << "\n";
}
template <typename T>
void outvv(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        outv(v);
    }
}
void outvvmint(const vector<vector<mint>>& vv) {
    for (const auto& v : vv) {
        outvmint(v);
    }
}
template <typename T>
void outvp(const vector<pair<T, T>>& vp) {
    for (const auto& p : vp) {
        cout << p.first << " " << p.second << "\n";
    }
}

ll N, H, W;
vvbool covered;
bool check(ll i, ll j, vpll& AB, ll idx) {
    // cout << i << " " << j << " " << idx << endl;
    bool ok = true;
    while (covered[i][j]) {
        j++;
        if (j == W) {
            j = 0;
            i++;
        }
        if (i == H) {
            return true;
        }
    }
    rep(k, N) {
        if (!(idx & (1 << k))) continue;
        ll a = AB[k].first;
        ll b = AB[k].second;
        bool ok2 = true;
        if (i + a <= H && j + b <= W) {
            rep(l, a) {
                rep(m, b) {
                    if (covered[i + l][j + m]) {
                        ok2 = false;
                        break;
                    }
                    covered[i + l][j + m] = true;
                }
            }
            if (ok2) {
                if (check(i, j, AB, idx ^ (1 << k))) {
                    return true;
                }
            }
            rep(l, a) {
                rep(m, b) { covered[i + l][j + m] = false; }
            }
        }
        if (a != b && i + b <= H && j + a <= W) {
            ok2 = true;
            rep(l, b) {
                rep(m, a) {
                    if (covered[i + l][j + m]) {
                        ok2 = false;
                        break;
                    }
                    covered[i + l][j + m] = true;
                }
            }
            if (ok2) {
                if (check(i, j, AB, idx ^ (1 << k))) {
                    return true;
                }
            }
            rep(l, b) {
                rep(m, a) { covered[i + l][j + m] = false; }
            }
        }
    }

    return false;
}

int main() {
    cin >> N >> H >> W;
    covered.resize(H, vbool(W, false));
    vpll AB;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        AB.push_back({a, b});
    }

    rep(i, 1 << N) {
        ll sum = 0;
        rep(j, N) {
            if (i & (1 << j)) {
                sum += AB[j].first * AB[j].second;
            }
        }
        if (sum != H * W) continue;

        if (check(0, 0, AB, i)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
