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
void outvmint(const vector<mint>& v) {
    for (const auto& e : v) {
        cout << e.val() << " ";
    }
    cout << endl;
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
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll maxA = 0;
    vvll A(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            cin >> A.at(i).at(j);
            maxA = max(maxA, A.at(i).at(j));
        }
    }

    ll l = -1, r = maxA + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        vvll S(N + 1, vll(N + 1, 0));
        rep(i, N) {
            rep(j, N) {
                S.at(i + 1).at(j + 1) = S.at(i + 1).at(j) + S.at(i).at(j + 1) - S.at(i).at(j) + (A.at(i).at(j) > mid);
            }
        }
        bool ok = false;
        for (ll i = 0; i + K <= N; i++) {
            for (ll j = 0; j + K <= N; j++) {
                ll cnt = S.at(i + K).at(j + K) - S.at(i).at(j + K) - S.at(i + K).at(j) + S.at(i).at(j);
                if (cnt <= K * K / 2) {
                    ok = true;
                }
            }
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;


    return 0;
}
