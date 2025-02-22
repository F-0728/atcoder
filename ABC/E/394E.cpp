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

int main() {
    ll N;
    cin >> N;
    vector<string> C(N);
    rep(i, N) { cin >> C[i]; }

    vvll dist(N, vll(N, INF));
    rep(i, N) {
        dist.at(i).at(i) = 0;
    }
    queue<pll> q;
    rep(i, N) {
        q.push({i, i});
    }
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (C[i][j] != '-') {
                dist[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [s, t] = q.front();
        q.pop();
        ll d = dist.at(s).at(t);
        rep(i, N) {
            rep(j, N) {
                if (C.at(i).at(s) == '-' || C.at(t).at(j) == '-') continue;
                if (C.at(i).at(s) == C.at(t).at(j)) {
                    if (C[i][s] == C[t][j]) {
                        if (dist[i][j] > d + 2) {
                            dist[i][j] = d + 2;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
    }

    rep(i, N) {
        rep(j, N) {
            if (dist.at(i).at(j) == INF) {
                cout << -1 << " ";
            } else {
                cout << dist.at(i).at(j) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
