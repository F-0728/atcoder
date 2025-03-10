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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) { cin >> S[i]; }

    vvll G(N);
    rep(i, N) {
        rep(j, M) {
            if (S[i][j] == '1') {
                G[i + j + 1].push_back(i);
            }
        }
    }

    vll dp(N, INF);
    dp[N - 1] = 0;
    for (ll i = N - 1; i >= 0; i--) {
        for (auto to : G[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }

    // outv(dp);

    vll dpforward(N, INF);
    dpforward[0] = 0;
    for (ll i = 0; i < N; i++) {
        rep(j, M) {
            if (S[i][j] == '1') {
                dpforward[i + j + 1] = min(dpforward[i + j + 1], dpforward[i] + 1);
            }
        }
    }

    vll ans(N, INF);
    rep(i, N) {
        vpll v;
        rep(j, M) {
            if (S[i][j] == '1') {
                v.push_back({dp[i + j + 1], i + j + 1});
            }
        }
        sort(v.begin(), v.end());
        ll minset = i;
        for (auto [d, to] : v) {
            for (ll j = minset + 1; j < to; j++) {
                ans[j] = min(ans[j], d + 1 + dpforward[i]);
            }
            minset = max(minset, to - 1);
        }
    }

    for (ll i = 1; i < N - 1; i++) {
        if (ans[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}
